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

  worm.reset(3, 3);
  worm.addPiece(3, 2);
  worm.addPiece(3, 1);

  goal = levelsData[level].goal;
  tutorial = levelsData[level].tutorial;
  currentLevel = level;
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
}

void Level::render() {
  tinyfont.setCursor(10, 10);
  tinyfont.print(tutorial);
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
      if (poop[row] & (1 << (15 - col))) {
        arduboy.drawBitmap(col * 8, row * 8, bmp_poop, 8, 8);
      }
    }
  }
  worm.render();
  arduboy.drawBitmap(goal.y * 8, goal.x * 8, bmp_goal, 8, 8);
}
