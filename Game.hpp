#pragma once

#include <vector>

#include "Hero.hpp"
#include "Monster.hpp"

const int plusInitHability = 6;
const int plusInitEnergy = 12;
const int plusInitLuck = 6;

class Game {
private:
  bool playing;
  Hero hero;
  std::vector<Monster> monsters;
  DiceSix d1;
  DiceSix d2;

  char getch();
  void setUpGame();
public:
  Game();
  void start();
};
