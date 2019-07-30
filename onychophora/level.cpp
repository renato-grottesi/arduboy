#include "level.h"
#include "bitmaps.h"

void Level::init(uint8_t level) {
  static uint16_t level_001_rock[8] = {
      0b1111111111111111, /**/
      0b1000000000000001, /**/
      0b1000000000000001, /**/
      0b1000000000000001, /**/
      0b1000000000000001, /**/
      0b1000001000000001, /**/
      0b1000011100000001, /**/
      0b1111111111111111, /**/
  };
  static uint16_t level_001_soil[8] = {
      0b0000000000000000, /**/
      0b0000000000011000, /**/
      0b0000000000011000, /**/
      0b0000000000011000, /**/
      0b0000000000011000, /**/
      0b0000000000011000, /**/
      0b0000000000011000, /**/
      0b0000000000000000, /**/
  };
  static uint16_t level_001_food[8] = {
      0b1111111111111111, /**/
      0b1000000000000001, /**/
      0b1000000000000001, /**/
      0b1000000000000001, /**/
      0b1000001000000001, /**/
      0b1000000000000001, /**/
      0b1000000000000001, /**/
      0b1111111111111111, /**/
  };

  for (uint8_t row = 0; row < 8; row++) {
    rock[row] = level_001_rock[row];
    soil[row] = level_001_soil[row];
    food[row] = level_001_food[row];
  }

  worm.reset(3, 3);
  worm.addPiece(3, 2);
  worm.addPiece(3, 1);

  goal.set(6, 14);
}

void Level::onInput(Direction dir) {
  if ((!is.moving) && (!is.falling)) {

    Cell newHead = worm.getHead();

    switch (dir) {
    case Direction::up:
      newHead.x--;
      break;
    case Direction::down:
      newHead.x++;
      break;
    case Direction::left:
      newHead.y--;
      break;
    case Direction::right:
      newHead.y++;
      break;
    }

    updateWorm(newHead);
  }
}

void Level::updateWorm(Cell newHead) {
  if (rock[newHead.x] & (1 << (15 - newHead.y))) {
    return;
  }

  bool enlarge = false;

  if (food[newHead.x] & (1 << (15 - newHead.y))) {
    food[newHead.x] &= ~(1 << (15 - newHead.y));
    enlarge = true;
  }

  worm.moveTo(newHead, enlarge, false);

  if (soil[newHead.x] & (1 << (15 - newHead.y))) {
    soil[newHead.x] &= ~(1 << (15 - newHead.y));
  }
}

void Level::update() {
  if (worm.fall(rock, soil)) {
    updateWorm(worm.getHead());
  }
}

void Level::render() {
  for (uint8_t row = 0; row < 8; row++) {
    for (uint16_t col = 0; col < 16; col++) {
      if (rock[row] & (1 << (15 - col))) {
        arduboy.drawBitmap(col * 8, row * 8, bmp_rock, 8, 8);
      }
      if (soil[row] & (1 << (15 - col))) {
        arduboy.drawBitmap(col * 8, row * 8, bmp_soil, 8, 8);
      }
      if (food[row] & (1 << (15 - col))) {
        arduboy.drawBitmap(col * 8, row * 8, bmp_food, 8, 8);
      }
    }
  }
  worm.render();
  arduboy.drawBitmap(goal.y * 8, goal.x * 8, bmp_goal, 8, 8);
}
