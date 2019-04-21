#include <iostream>

#include "Char.hpp"
#include "Hero.hpp"

Hero::Hero(int h, int e, int l) : Char(h, e), luck(l), initLuck(l) {
}

void Hero::increaseInitLuck() {initLuck++;}
void Hero::decreaseInitLuck() {initLuck--;}
void Hero::increaseInitLuck(int p) {initLuck += p;}
void Hero::decreaseInitLuck(int p) {initLuck -= p;}
void Hero::increaseLuck() {luck++;}
void Hero::decreaseLuck() {luck--;}
void Hero::increaseLuck(int p) {luck += p;}
void Hero::decreaseLuck(int p) {luck -= p;}

void Hero::printStatus() {
  Char::printStatus();
  std::cout << "Initial Luck: " << initLuck << std::endl;
  std::cout << "Luck: " << luck << std::endl;
}
