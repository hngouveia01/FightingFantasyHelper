#include <unistd.h>   //_getch*/
#include <termios.h>  //_getch*/
#include <vector>
#include <iostream>

#include "DiceSix.hpp"
#include "Hero.hpp"
#include "Game.hpp"
#include "Monster.hpp"

Game::Game() : hero(0, 0, 0) {
  playing = false;
  d1 = DiceSix();
  d2 = DiceSix();
  setUpGame();
}

void Game::setUpGame() {
  int initHability = d1.rollDice() + plusInitHability;
  int initEnergy = d1.rollDice() + d2.rollDice() + plusInitEnergy;
  int initLuck = d1.rollDice() + plusInitLuck;
  hero.increaseInitHability(initHability);
  hero.increaseInitEnergy(initEnergy);
  hero.increaseInitLuck(initLuck);
  hero.increaseHability(initHability);
  hero.increaseEnergy(initEnergy);
  hero.increaseLuck(initLuck);
}

char Game::getch(){
    char buf=0;
    struct termios old={0};
    fflush(stdout);
    if(tcgetattr(0, &old)<0)
        perror("tcsetattr()");
    old.c_lflag&=~ICANON;
    old.c_lflag&=~ECHO;
    old.c_cc[VMIN]=1;
    old.c_cc[VTIME]=0;
    if(tcsetattr(0, TCSANOW, &old)<0)
        perror("tcsetattr ICANON");
    if(read(0,&buf,1)<0)
        perror("read()");
    old.c_lflag|=ICANON;
    old.c_lflag|=ECHO;
    if(tcsetattr(0, TCSADRAIN, &old)<0)
        perror ("tcsetattr ~ICANON");
    printf("%c\n",buf);
    return buf;
}

void Game::start() {
  playing = true;
  bool fighting = false;
  bool gettingMonsters = false;
  char key = 0;
  bool waitingKey = false;
  DiceSix d1 = DiceSix();
  DiceSix d2 = DiceSix();

  while(playing) {
    std::cout << "Your hero stats are:" << std::endl;
    hero.printStatus();
    std::cout << "Press any key to register monster..." << std::endl;
    std::cin >> key;
    gettingMonsters = true;

    while(gettingMonsters) {
      int hability = 0;
      int energy = 0;

      std::cout << "Enter hability:" << std::endl;
      std::cin >> hability;
      std::cout << "Enter energy:" << std::endl;
      std::cin >> energy;
      waitingKey = true;

      while(waitingKey) {
        monsters.push_back(Monster(hability, energy));
        std::cout << "OK.. want to register another one?[Y/n]";
        key = getch();
        if ('\n' != key && 'Y' != key && 'y' != key) {
          waitingKey = false;
        }
      }
      gettingMonsters = false;
    }
    fighting = true;
    while(fighting) {
      int i = 1;
      for(auto &monster : monsters) {
        std::cout << i << std::endl;
        std::cout << ": " << std::endl;
        monster.printStatus();
        std::cout << std::endl;
        i++;
      }
      fighting = false;
    }
  }
  playing = false;
}
