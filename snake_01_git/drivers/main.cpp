/**
 * @file main.cpp
 * @author Florian Leuze (3308288) <st155013@stud.uni-stuttgart.de>
 * @date 13.03.2018
 * @brief Main Function of the snake game. Organises calls, basic functions and later menu
 */

//Standard includes
#include <iostream>
#include <string>
#include <stdlib.h>
#include <list>
#include <vector>
#include <forward_list>
//Classes
#include "../include/Food.h"
#include "Gamewindow.h"
#include "Parameters.h"
#include "Snakepart.h"
#include "gdpc.h"
//Other Header Files
#include "smallFunctions.h"
/**
 * @brief Parameter Object for global parameters. Not really used anymore, was a bad idea to begin with.
 */
Parameters par;
/**
 * @brief Generates a two way List with type Snakepart. This stores the head as well as every following snakepart
 * (yes a vector would have been better)
 */
std::list<Snakepart> snakeList;

/**
 * @brief This just initializes everything (beginning with the gamewindow, the head of the snake, food, and so on).
 * It takes most information needed out of the SnakeList and par
 */
int initializeEverything();
/**
 * @brief Handles everything about the menu (drawing, keypressing, and so on.
 * @param val Bool value. If true new Gamewindow will be created. If False the Gamewindow will be deleted.
 * @param m Gamewindow type pointer to the gamewindow that shall be deleted. If val is set to true this parameter
 * should be set to NULL.
 */
Gamewindow* startupMenu(bool val, Gamewindow* m);
/**
 * @brief This function needs to be called in a lopp and organises the movement of the Snake. As long as the
 * direction is not "STOP" (which will never happen unless the game starts) this function should create
 * an endless movement.
 */
int movement(Gamewindow* wd);
/**
 * @brief This is the handler for the keypress input while playing strictly defined after the documentation of dgpc.
 */
static void control(char* s, const void* object);
/**
 * @brief This is the handler for the keypress input in the menu strictly defined after the documentation of dgpc.
 */
static void control2(char* s, const void* object);
/**
 * @brief This function just prints information to stdout about every Snakepart type object in the list. Mainly for debugging.
 */
void browseList(std::list<Snakepart> s);
/**
 * @brief Organises calls of deconstructors and clean exit.
 */
int exitStuff(Snakepart* sn);

/**
 * @brief Main function organises calling of every game function.
 */
int main(void) {
  while (true) {
    Gamewindow* m = startupMenu(true, NULL);
    sleep(1);
    startupMenu(false, m);
    sleep(1);
    initializeEverything();
    while (true) {
      if (movement(par.getGameWindow()) == 1)
        break;
    }
    //exitStuff(&(*snakeList.begin()));
  }
  return 0;
}

static void control2(char* s, const void* object) {
  std::cout << *s << std::endl;
  Gamewindow* temp = (Gamewindow*) object;
  switch (*s) {
  case 'U':
    if (*temp->getMenu() > 0)
      temp->setMenu((*temp->getMenu()) - 1);
    //*s = '\0';
    break;
  case 'D':
    if (*temp->getMenu() < 3)
      temp->setMenu((*temp->getMenu()) + 1);
    //*s = '\0';
    break;
  case 'R':
    temp->setMenu((*temp->getMenu()), 1);
    break;
  }
}

Gamewindow* startupMenu(bool val, Gamewindow* m) {
  if (val == true) {
    Gamewindow* menu = new Gamewindow(400, 150);
    menu->setMenu(0, 0);
    GDPC_register_keypress_handler(menu->getGdpc(), control2, menu);
    while ((menu->getMenu())[1] == 0) {
      menu->drawFrame(0, "New Game", true);
      std::cout << "Score: " << par.getScore() << std::endl;
      std::string score = "Current Score: " + std::to_string(par.getScore());
      menu->drawFrame(1, score, true);
      menu->drawFrame(2, "Not yet implemented", true);
      menu->drawFrame(3, "End", true);
      mSleep(500);
      menu->drawFrame(*menu->getMenu(), "Test", false, 255, 102, 102);
      mSleep(500);
    }
    switch (*menu->getMenu()) {
    case 0:
      menu->setMenu(0, 0);
      return menu;
      break;
    case 1:
      menu->setMenu(0, 0);
      break;
    case 2:
      menu->setMenu(0, 0);
      break;
    case 3:
      menu->setMenu(0, 0);
      GDPC_force_destroy(menu->getGdpc());
      delete menu;
      exit(1);
      break;
    }
    return menu;
  } else {
    std::cout << "Starting to destroy the gdpc" << std::endl;
    GDPC_force_destroy(m->getGdpc());
    delete m;
    return NULL;
  }
}

int initializeEverything() {
  //initialize parameter object
  //generate field
  Gamewindow* wd = new Gamewindow(1000, 800);
  Snakepart snake(&snakeList);
  snake.setFirst(true);
  snake.setPosX(50);
  snake.setPosY(50);
  snake.setOldPosX(0);
  snake.setOldPosY(0);
  snakeList.push_front(snake);
  Food* food = new Food();
  food->generateCoordiantes(wd->getCoord(), wd);
  food->drawFood(wd->getGdpc());
  sleep(1);
  //load parameter object
  par.loadParameters(wd->getGdpc(), wd, &snake, food, 10);
  par.setScore(0);
  snakeList.begin()->drawWorm(wd, food);
  GDPC_register_keypress_handler(par.getGdpc(), control, wd);
  return 0;
}

int movement(Gamewindow* wd) {
  if (snakeList.begin()->getDir() != STOP) {
    std::cout << "X: " << snakeList.begin()->getPosX() << std::endl << "Y: "
        << snakeList.begin()->getPosY() << std::endl;
    std::cout << "Food X: " << par.getFood()->getCoord().getX() << std::endl
        << "Food Y: " << par.getFood()->getCoord().getY() << std::endl;
    snakeList.begin()->moveWorm(wd, par.getFood());
    par.getFood()->getCoord().printCoord();
    Food* temp = snakeList.begin()->collision(wd, par.getFood());
    if (temp == NULL) {
      std::cout << "GAMEOVER!!!" << std::endl;
      par.setScore((int) snakeList.size());
      sleep(1);
      exitStuff(&(*snakeList.begin()));
      std::cout << "Survived exitStuff" << std::endl;
      sleep(5);
      return 1;
    }
    par.setFood(temp);
    if(snakeList.size()*2 <= 150)
      mSleep(150-snakeList.size()*2);
    else
      mSleep(0);
  }
  return 0;
}

static void control(char* s, const void* object) {
  std::cout << *s << std::endl;
  Gamewindow* window = par.getGameWindow();
//  std::cout << "X before: " << snakeList.begin()->getPosX()
//      << std::endl << "Y before: " << snakeList.begin()->getPosY() << std::endl << std::endl;
  eDirection dir = STOP;
  switch (*s) {
  case 'U':
    dir = UP;
    break;
  case 'D':
    dir = DOWN;
    break;
  case 'L':
    dir = LEFT;
    break;
  case 'R':
    dir = RIGHT;
    break;
  default:
    dir = STOP;
    break;
  }
  if (dir != STOP)
    snakeList.begin()->moveWorm(window, dir, par.getFood());
//  std::cout << "Old X: " << snakeList.begin()->getOldPosX()
//        << std::endl << "Old Y: " << snakeList.begin()->getOldPosY() << std::endl << std::endl;
//  std::cout << "X after: " << snakeList.begin()->getPosX()
//        << std::endl << "Y after: " << snakeList.begin()->getPosY() << std::endl << std::endl;
}

void browseList(std::list<Snakepart> s) {
  int i = 0;
  for (auto it = s.begin(); it != s.end(); ++it) {
    Snakepart s = *it;
    std::cout << "First object?: " << std::endl << "Number" << i << ": "
        << std::boolalpha << it->isFirst() << std::noboolalpha << std::endl;
    std::cout << "Coordinates x/y: " << it->getPosX() << "/" << it->getPosY()
        << std::endl;
    std::cout << "Old Coordiantes x/y: " << it->getOldPosX() << "/"
        << it->getOldPosY() << std::endl;
    ++i;
  }
}

int exitStuff(Snakepart* sn) {
  std::cout << "Entered exitStuff" << std::endl;
  int i = 0;
  GDPC_unregister_keypress_handler(par.getGdpc(), control, par.getGameWindow());
  while(GDPC_force_destroy(par.getGdpc())){
    if (i>1000){
      exit(1);
    }
  }
  std::cout << "GDPC deleted" << std::endl;
  delete par.getGameWindow();
  std::cout << "Gamewindow deleted" << std::endl;
  delete par.getFood();
  std::cout << "Food deleted" << std::endl;
  snakeList.clear();
  par.resetPar();
  return 1;
}

