#include <iostream>
#include <time.h>

#include "Dice.hpp"

void Dice::printResult() {
  std::cout << getResult() << std::endl;
}

int Dice::rollDice() {
  struct timespec ts;

  clock_gettime(CLOCK_MONOTONIC, &ts);

  srand((time_t) ts.tv_nsec);

  setResult(rand() % (getFaces()) + 1);

  return getResult();
}
