#include <iostream>

#include "Char.hpp"

Char::Char(int h, int e) : initHability(h), hability(h), initEnergy(e), energy(e) {
}

/* manage hability stat */
void Char::increaseInitHability() {initHability++;}
void Char::decreaseInitHability() {initHability--;}
void Char::increaseInitHability(int p) {initHability += p;}
void Char::decreaseInitHability(int p) {initHability -= p;}
void Char::increaseHability() {hability++;}
void Char::decreaseHability() {hability--;}
void Char::increaseHability(int p) {hability += p;}
void Char::decreaseHability(int p) {hability -= p;}

/* manage energy stat */
void Char::increaseInitEnergy() {initEnergy++;}
void Char::decreaseInitEnergy() {initEnergy--;}
void Char::increaseInitEnergy(int p) {initEnergy += p;}
void Char::decreaseInitEnergy(int p) {initEnergy -= p;}
void Char::increaseEnergy() {energy++;}
void Char::decreaseEnergy() {energy--;}
void Char::increaseEnergy(int p) {energy += p;}
void Char::decreaseEnergy(int p) {energy -= p;}

void Char::printStatus() {
  std::cout << "Initial Hability: " << initHability << std::endl;
  std::cout << "Hability: " << hability << std::endl;
  std::cout << "Initial Energy: " << initEnergy << std::endl;
  std::cout << "Energy: " << energy << std::endl;
}
