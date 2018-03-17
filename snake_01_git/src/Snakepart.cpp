/**
 * @file Snakepart.cpp
 * @author Florian Leuze (3308288) <st155013@stud.uni-stuttgart.de>
 * @date 13.03.2018
 * @brief Brief description of the file
 */

#include "../include/Snakepart.h"

//constructor + destructor
Snakepart::Snakepart() {
  // TODO Auto-generated constructor stub
  //initialize everything
  coord.setX(0);
  coord.setY(0);
  coordOld.setX(coord.getX());
  coordOld.setY(coord.getY());
  number = 0;
  first = false;
  dir = STOP;
  s = NULL;
}

Snakepart::Snakepart(std::list<Snakepart> *p) {
  // TODO Auto-generated constructor stub
  //initialize everything
  coord.setX(0);
  coord.setY(0);
  coordOld.setX(coord.getX());
  coordOld.setY(coord.getY());
  number = 0;
  first = false;
  dir = STOP;
  s = p;
}

Snakepart::Snakepart(std::list<Snakepart> sn, std::list<Snakepart> *p) {
  //initialize everything
  coord.setX(0);
  coord.setY(0);
  coordOld.setX(coord.getX());
  coordOld.setY(coord.getY());
  number = 0;
  first = false;
  dir = STOP;
  auto it = sn.end();
  Snakepart l;
  if (sn.empty() == false)
    l = *(--it);
  else
    l = *it;
  coord.setX(l.getOldPosX());
  coord.setY(l.getOldPosY());
  s = p;
}

Coordinates Snakepart::moveWorm(Gamewindow* wd, eDirection d, Food* food) {
  dir = d;
  switch (dir) {
  case 0:
    break;
  case 1:  //LEFT
    exchCoord(coord, coordOld);
    coord.setX((int) (coord.getX() - snakeSize));
    break;
  case 2:  //RIGHT
    exchCoord(coord, coordOld);
    coord.setX((int) (coord.getX() + snakeSize));
    break;
  case 3:  //UP
    exchCoord(coord, coordOld);
    coord.setY((int) (coord.getY() - snakeSize));
    break;
  case 4:  //DOWN
    exchCoord(coord, coordOld);
    coord.setY((int) (coord.getY() + snakeSize));
    break;
  }
  followLast();
  drawWorm(wd, food);
  return coord;
}

Coordinates Snakepart::moveWorm(Gamewindow* wd, Food* food) {
  int stepLength = snakeSize; //snakeSize
  switch (dir) {
  case 0:
    break;
  case 1:  //LEFT
    exchCoord(coord, coordOld);
    coord.setX((int) (coord.getX() - stepLength));
    break;
  case 2:  //RIGHT
    exchCoord(coord, coordOld);
    coord.setX((int) (coord.getX() + stepLength));
    break;
  case 3:  //UP
    exchCoord(coord, coordOld);
    coord.setY((int) (coord.getY() - stepLength));
    break;
  case 4:  //DOWN
    exchCoord(coord, coordOld);
    coord.setY((int) (coord.getY() + stepLength));
    break;
  }
  followLast();
  drawWorm(wd, food);
  return coord;
}

void Snakepart::followLast(std::list<Snakepart> sn) {
  if (first == false) {
    coordOld.setX(coord.getX());
    coordOld.setY(coord.getY());
    auto it = sn.end();
    Snakepart l;
    if (sn.empty() == false)
      l = *(--it);
    else
      l = *it;
    std::cout << "x/y" << l.getOldPosX() << "/" << l.getOldPosY() << std::endl;
    coord.setX(l.getOldPosX());
    coord.setY(l.getOldPosY());
  }
}

void Snakepart::followLast() {
  if (s != NULL) {
    if ((first == true) && (s->empty() == false)) {
      int i = 0;
      auto iter = s->begin();
      auto iter2 = ++s->begin();
      if ((iter->getOldPosX() != iter2->getPosX())
          || (iter->getOldPosY() != iter2->getPosY())) {
        for (auto it = s->begin(); it != s->end(); ++it) {
          if (it == s->begin()) {
          } else {
            auto temp = it;
            auto tempMinus = --it;
            ++it;
            temp->setOldPosX(temp->getPosX());
            temp->setOldPosY(temp->getPosY());
            temp->setPosX(tempMinus->getOldPosX());
            temp->setPosY(tempMinus->getOldPosY());
          }
          ++i;
          if (i > 100)
            break;
        }
      }
    }
  }
}

void Snakepart::followLast(Snakepart *a, Snakepart *b) {
  a->setOldPosXY(a->getPosX(), a->getPosY());
  std::cout << "x/y" << a->getOldPosX() << "/" << a->getOldPosY() << std::endl;
  b->setPosX(a->getOldPosX());
  b->setPosY(a->getOldPosY());
}

void Snakepart::exchCoord(Coordinates &a, Coordinates &b) {
  b.setX(a.getX());
  b.setY(a.getY());
}

void Snakepart::browseList() {
  int i = 0;
  for (auto it = s->begin(); it != s->end(); ++it) {
    std::cout << "First object?: " << std::endl << "Number" << i << ": "
        << std::boolalpha << it->isFirst() << std::noboolalpha << std::endl;
    std::cout << "Coordinates x/y: " << it->getPosX() << "/" << it->getPosY()
        << std::endl;
    std::cout << "Old Coordiantes x/y: " << it->getOldPosX() << "/"
        << it->getOldPosY() << std::endl;
    ++i;
  }
}

int Snakepart::drawWorm(Gamewindow* wd, Food* food) {
  wd->clearWindow();
  int circleVal = 0;
  if (s != NULL) {
    if ((first == true) && (s->empty() == false)) {
      for (auto it = s->begin(); it != s->end(); ++it) {
        Snakepart l = *it;
        if (it == s->begin()) {
          circleVal = GDPC_circle(wd->getGdpc(), coord.getX(), coord.getY(),
              snakeSize, true);
        } else {
          circleVal = GDPC_circle(wd->getGdpc(), l.getPosX(), l.getPosY(),
              (int) (snakeSize * 0.5), false);
        }
      }
    }
  }
  food->drawFood(wd->getGdpc());
  fixCoord(coord, coordOld, wd);
  return circleVal;

}

void Snakepart::fixCoord(Coordinates &n, Coordinates &o, Gamewindow* wd) {
  switch (dir) {
  case 0:
    break;
  case 1:  //LEFT
    if ((n.getX() - (int) (snakeSize / 2)) <= 2) {
      o.setX(n.getX());
      n.setX(wd->getCoord().getX() - (int) (snakeSize / 2));
    }
    break;
  case 2:  //RIGHT
    if ((n.getX() + (int) (snakeSize / 2)) + 2 >= wd->getCoord().getX()) {
      o.setX(n.getX());
      n.setX((int) (snakeSize / 2));
    }
    break;
  case 3:  //UP
    if ((n.getY() - (int) (snakeSize / 2)) <= 2) {
      o.setY(n.getY());
      n.setY(wd->getCoord().getY() - (int) (snakeSize / 2));
    }
    break;
  case 4:  //DOWN
    if ((n.getY() + (int) (snakeSize / 2)) + 2 >= wd->getCoord().getY()) {
      o.setY(n.getY());
      n.setY((int) (snakeSize / 2));
      break;
    }
  }
}

Food* Snakepart::collision(Gamewindow* wd, Food* f) {
  Coordinates snake = coord;
  Coordinates food = f->getCoord();

  int minDist = (int) round((f->getFoodSize() + snakeSize) / 2);
  int realDist = (int) round(sqrt(std::pow((abs(snake.getX() - food.getX())), 2)
              + std::pow((abs(snake.getY() - food.getY())), 2)));
  std::cout << "minDist: " << minDist << std::endl << "realDist: " << realDist << std::endl;
  if (realDist <= (minDist+1)) {
    std::cout << "Collision detected!" << std::endl;
    s->push_back(Snakepart(*s, s));
    delete f;
    Food* food = new Food();
    food->generateCoordiantes(wd->getCoord(), wd);
    food->drawFood(wd->getGdpc());
    return food;
  }
  else {
    for (auto it = s->begin(); it != s->end(); ++it) {
      if (it == s->begin()) {
      } else {
        if ((it->getPosX() == coord.getX())
            && (it->getPosY() == coord.getY())) {
          std::cout << "PosX: " << it->getPosX() << " HeadX: " << coord.getX()
              << std::endl << "PosY: " << it->getPosY() << " Head>: "
              << coord.getY() << std::endl;
          //sleep(2);
          return NULL;
        }
      }
    }
  }
  return f;
}

Snakepart::~Snakepart() {
  if (first == false) {
    for (auto it = s->begin(); it != s->end(); ++it) {
      if (it == s->begin()) {
      } else {
      }
    }
  }
}

//Getters
int Snakepart::getPosX() {
  return coord.getX();
}

int Snakepart::getPosY() {
  return coord.getY();
}

int Snakepart::getOldPosX() {
  return coordOld.getX();
}

int Snakepart::getOldPosY() {
  return coordOld.getY();
}

int Snakepart::getNumber() {
  return number;
}

eDirection Snakepart::getDir() {
  return dir;
}

bool Snakepart::isFirst() {
  return first;
}

//Setter
int Snakepart::setPosX(int coordinate) {
  coord.setX(coordinate);
  return 0;
}

int Snakepart::setPosY(int coordinate) {
  coord.setY(coordinate);
  return 0;
}

int Snakepart::setPosXY(int y, int x) {
  coord.setX(x);
  coord.setY(y);
  return 0;
}

int Snakepart::setOldPosX(int oldCoordinate) {
  coordOld.setX(oldCoordinate);
  return 0;
}

int Snakepart::setOldPosY(int oldCoordinate) {
  coordOld.setY(oldCoordinate);
  return 0;
}

int Snakepart::setOldPosXY(int oldY, int oldX) {
  coordOld.setX(oldX);
  coordOld.setY(oldY);
  return 0;
}

int Snakepart::setNumber(int n) {
  number = n;
  return 0;
}

int Snakepart::setFirst(bool f) {
  first = f;
  return 0;
}

//Helpers
void Snakepart::resetEverything() {
  coord.setX(0);
  coord.setY(0);
  coordOld.setX(coord.getX());
  coordOld.setY(coord.getY());
  number = 0;
  first = false;
  dir = STOP;
}
