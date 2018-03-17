/**
 * @file Coordinates.cpp
 * @author Florian Leuze (3308288) <st155013@stud.uni-stuttgart.de>
 * @date 13.03.2018
 * @brief Brief description of the file
 */

#include "../include/Coordinates.h"

Coordinates::Coordinates() {
  posX = 0;
  posY = 0;
  // TODO Auto-generated constructor stub
}

Coordinates::Coordinates(int x, int y) :
    posX(x), posY(y) {
}

int Coordinates::setX(int x) {
  posX = x;
  return 0;
}

int Coordinates::setY(int y) {
  posY = y;
  return 0;
}

void Coordinates::printCoord() {
  //sleep(1);
  std::cout << "Coordinate Print" << std::endl;
  std::cout << "X: " << posX << std::endl << "Y: " << posY << std::endl
      << std::endl;
}

void Coordinates::fixCoordinates(Coordinates wd, int size) {
  bool fix = false;
  do {
    fix = true;
    if ((posX - (int) (size / 2)) <= 5) {
      posX = wd.getX() - (int) (size / 2) - 2;
      fix = false;
    }

    else if ((posX + (int) (size / 2))+5 >= wd.getX()) {
      posX = (int) (size / 2) + 2;
      fix = false;
    }

    if ((posY - (int) (size / 2)) <= 5) {
      posY = wd.getY() - (int) (size / 2) - 2;
      fix = false;
    }

    else if ((posY + (int) (size / 2))+5 >= wd.getY()) {
      posY = (int) (size / 2) + 2;
      fix = false;
    }
  }
  while(fix == false);
}

int Coordinates::getX() {
  return posX;
}

int Coordinates::getY() {
  return posY;
}

