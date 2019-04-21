#pragma once

#include <cstdlib>

class Dice {
private:
  int result;
  int faces;
protected:
  void setResult(int r) {result = r;}
public:
  Dice(int f) {faces = f; result = 0;}

  int rollDice();
  void setFaces(int f) {faces = f;}
  int getResult() {return result;}
  int getFaces() {return faces;}
  void printResult();
};
