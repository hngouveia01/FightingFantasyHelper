#pragma once

#include "Char.hpp"

class Hero : public Char {
private:
  int initLuck;
  int luck;

public:
  Hero(int h, int e, int l);
  void printStatus() override;

  void increaseInitLuck();
  void decreaseInitLuck();
  void increaseInitLuck(int p);
  void decreaseInitLuck(int p);
  void increaseLuck();
  void decreaseLuck();
  void increaseLuck(int p);
  void decreaseLuck(int p);
};
