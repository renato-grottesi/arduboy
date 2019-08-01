#include "level.h"
#include "bitmaps.h"
#include "levels.h"

void Level::init(uint8_t level) {

  for (uint8_t row = 0; row < 8; row++) {
    rock[row] = levelsData[level].rock[row];
    soil[row] = levelsData[level].soil[row];
    food[row] = levelsData[level].food[row];
    poop[row] = levelsData[level].poop[row];
  }

  worm.reset(levelsData[level].head);
  worm.addPiece(levelsData[level].body);
  worm.addPiece(levelsData[level].tail);

  goal = levelsData[level].goal;
  tutorial = levelsData[level].tutorial;
  currentLevel = level;
}

void Level::onInput(Direction dir) {
  if ((!is.moving) && (!is.falling)) {

    Cell newHead = worm.getHead();

    switch (dir) {
    case Direction::up:
      if (newHead.x == 0) {
        return;
      };
      newHead.x--;
      break;
    case Direction::down:
      if (newHead.x == 7) {
        return;
      };
      newHead.x++;
      break;
    case Direction::left:
      if (newHead.y == 0) {
        return;
      };
      newHead.y--;
      break;
    case Direction::right:
      if (newHead.y == 15) {
        return;
      };
      newHead.y++;
      break;
    }

    updateWorm(newHead);
  }
}

void Level::updateWorm(Cell newHead) {
  if (newHead.intersects(rock)) {
    return;
  }

  bool enlarge = false;
  bool shrink = false;

  if (newHead.intersects(food)) {
    newHead.resetTilemap(food);
    enlarge = true;
  }

  if (newHead.intersects(poop)) {
    newHead.resetTilemap(poop);
    shrink = true;
  }

  worm.moveTo(newHead, enlarge, shrink);

  if (newHead.intersects(soil)) {
    newHead.resetTilemap(soil);
  }
}

void Level::update() {
  if (worm.fall(rock, soil)) {
    updateWorm(worm.getHead());
  }
  if (worm.getHead().intersects(goal)) {
    currentLevel++;
    if (currentLevel >= levelsCount)
      currentLevel = 0;
    init(currentLevel);
  }

  uint16_t stable[8];
  for (uint8_t row = 0; row < 8; row++) {
    stable[row] = rock[row];
  }

  uint16_t oldStable = 0;
  uint16_t newStable = 1;

  while (newStable != oldStable) {
    oldStable = newStable;
    newStable = 0;
    for (uint8_t row = 0; row < 8; row++) {
      for (uint8_t col = 0; col < 16; col++) {
        if (soil[row] & (1 << (15 - col))) {
          if ((row < 7 && (stable[row + 1] & (1 << (15 - col)))) ||
              (row > 0 && (stable[row - 1] & (1 << (15 - col)))) ||
              (col < 15 && (stable[row] & (1 << (15 - col + 1)))) ||
              (col > 0 && (stable[row] & (1 << (15 - col - 1)))) ||
              (row == 7 || row == 0 || col == 15 ||
               col == 0) /* Borders are safe. */
          ) {
            stable[row] |= (1 << (15 - col));
            newStable++;
          }
        }
      }
    }
  }

  for (uint8_t row = 6; row != 0; row--) {
    for (uint8_t col = 0; col < 16; col++) {
      if ((soil[row] & (1 << (15 - col))) &&
          !(stable[row] & (1 << (15 - col)))) {
        soil[row] &= ~(1 << (15 - col));
        soil[row + 1] |= (1 << (15 - col));
      }
    }
  }
}

void Level::render() {
  tinyfont.setCursor(0, 0);
  tinyfont.print(tutorial);
  for (uint8_t row = 0; row < 8; row++) {
    for (uint8_t col = 0; col < 16; col++) {
      if (rock[row] & (1 << (15 - col))) {
        arduboy.drawBitmap(col * 8, row * 8, bmp_rock, 8, 8);
      }
      if (soil[row] & (1 << (15 - col))) {
        arduboy.drawBitmap(col * 8, row * 8, bmp_soil, 8, 8);
      }
      if (food[row] & (1 << (15 - col))) {
        arduboy.drawBitmap(col * 8, row * 8, bmp_food, 8, 8);
      }
      if (poop[row] & (1 << (15 - col))) {
        arduboy.drawBitmap(col * 8, row * 8, bmp_poop, 8, 8);
      }
    }
  }
  worm.render();
  arduboy.drawBitmap(goal.y * 8, goal.x * 8, bmp_goal, 8, 8);
}
