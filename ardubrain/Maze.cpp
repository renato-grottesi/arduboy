#include "Maze.hpp"

void Maze::update() {
  millis += 31;  // 32 frames per second, so 31.25 ms are rounded to 31
  switch (status) {
    case Status::instructions:
      if (arduboy.justPressed(A_BUTTON)) {
        status = Status::showing;
        millis = 0;  // Reset the counter
        moves = 0;

        // TODO: generate a proper maze with proper start and goal
        for (uint8_t r = 0; r < 8; r++) {
          for (uint8_t c = 0; c < 16; c++) {
            maze[r][c] = (rand() % 4) == 1;
          }
        }
        posX = 0;
        posY = 0;
        goalY = 0;
        goalX = 14;
      }
      break;
    case Status::showing:
      if (millis > 2000) {
        moves = 0;
        millis = 0;
        status = Status::navigating;
      }
      break;
    case Status::navigating:
      if (arduboy.justPressed(UP_BUTTON)) {
        if (posY > 0 && (!maze[posY - 1][posX])) {
          posY--;
        }
        moves++;
      } else if (arduboy.justPressed(DOWN_BUTTON)) {
        if (posY < 7 && (!maze[posY + 1][posX])) {
          posY++;
        }
        moves++;
      } else if (arduboy.justPressed(LEFT_BUTTON)) {
        if (posX > 0 && (!maze[posY][posX - 1])) {
          posX--;
        }
        moves++;
      } else if (arduboy.justPressed(RIGHT_BUTTON)) {
        if (posX < 15 && (!maze[posY][posX + 1])) {
          posX++;
        }
        moves++;
      } else if (arduboy.justPressed(B_BUTTON)) {
        mScore = 0;
        status = Status::score;
      }
      if (posX == goalX && posY == goalY) {
        mScore = (100 - moves) * 8;  // TODO
        status = Status::score;
      }
      break;
    case Status::score:
      if (arduboy.justPressed(A_BUTTON)) {
        status = Status::done;
      }
      break;
    case Status::done:
      break;
  }
}

void Maze::render() {
  switch (status) {
    case Status::instructions:
      tinyfont.setCursor(16, 16);
      tinyfont.print(F(                           /**/
                       "WAIT FOR THE FIELD OF\n"  /**/
                       "VIEW TO REDUCE, THEN\n"   /**/
                       "NAVIGATE THE MAZE AND\n"  /**/
                       "REACH THE EXIT WITH AS\n" /**/
                       "FEW MOVEMENTS AS\n"       /**/
                       "POSSIBLE.\n"              /**/
                       ));
      break;
    case Status::showing:
      for (uint8_t r = 0; r < 8; r++) {
        for (uint8_t c = 0; c < 16; c++) {
          if (maze[r][c]) {
            arduboy.fillRect(c * 8, r * 8, 8, 8, WHITE);
          }
        }
      }
      break;
    case Status::navigating:
      for (int8_t r = posY - 1; r < posY + 2; r++) {
        for (int8_t c = posX - 1; c < posX + 2; c++) {
          if (r >= 0 && c >= 0 && r < 8 && c < 16 && maze[r][c]) {
            arduboy.fillRect(c * 8, r * 8, 8, 8, WHITE);
          }
        }
      }
      arduboy.fillCircle(4 + posX * 8, 4 + posY * 8, 3);
      arduboy.fillCircle(4 + goalX * 8, 4 + goalY * 8, 3);
      break;
    case Status::score:
      tinyfont.setCursor(1, 1);
      tinyfont.print(F("FINAL SCORE:"));
      tinyfont.setCursor(1, 32);
      tinyfont.print(mScore);
      break;
    case Status::done:
      break;
  }
}

bool Maze::complete(uint16_t& score) {
  score = mScore;
  return status == Status::done;
}
