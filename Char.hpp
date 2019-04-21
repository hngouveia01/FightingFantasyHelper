#pragma once

class Char {
private:
  int initHability;
  int initEnergy;
  int hability;
  int energy;

public:
  Char(int h, int e);

  void increaseInitHability();
  void decreaseInitHability();
  void increaseInitHability(int p);
  void decreaseInitHability(int p);
  void increaseHability();
  void decreaseHability();
  void increaseHability(int p);
  void decreaseHability(int p);

  void increaseInitEnergy();
  void decreaseInitEnergy();
  void increaseInitEnergy(int p);
  void decreaseInitEnergy(int p);
  void increaseEnergy();
  void decreaseEnergy();
  void increaseEnergy(int p);
  void decreaseEnergy(int p);

  virtual void printStatus();
};
