/**
 * @file Food.cpp
 * @author Florian Leuze (3308288) <st155013@stud.uni-stuttgart.de>
 * @date 13.03.2018
 * @brief Brief description of the file
 */

#include <math.h>
#include <stdlib.h>
#include <iostream>
#include "Food.h"

Food::Food() {
  coord.setX(0);
  coord.setY(0);
}

Food::Food(int x, int y){
  coord.setX(x);
  coord.setY(y);
}

Food::~Food() {
  //delete coord;
}

void Food::generateCoordiantes(Coordinates val, Gamewindow* wd) {
  //srand(time(NULL));
  //rand();
  mersenne_init(time(NULL));
   std::cout << mersenne() << std::endl << mersenne() << std::endl << MERSENNE_MAX << std::endl << std::endl;
   long double tempX = (long double) mersenne()/MERSENNE_MAX;
   long double tempY = (long double) mersenne()/MERSENNE_MAX;
   std::cout << "TempX: " << tempX << std::endl << "TempY: " << tempY << std::endl;
   coord.setX((int)(tempX * val.getX()));
   coord.setY((int)(tempY * val.getY()));
   coord.fixCoordinates(wd->getCoord(), foodSize);
   std::cout << "X: " << coord.getX() << std::endl << "Y: " << coord.getY() << std::endl;
   mersenne_term();
//  std::cout << rand() << std::endl << rand() << std::endl
//      << RAND_MAX << std::endl << std::endl;
//  long double tempX = (long double) rand() / RAND_MAX;
//  long double tempY = (long double) rand() / RAND_MAX;
//  std::cout << "TempX: " << tempX << std::endl << "TempY: " << tempY
//      << std::endl;
//  coord.setX((int) (tempX * val.getX()));
//  coord.setY((int) (tempY * val.getY()));
//  std::cout << "X: " << coord.getX() << std::endl << "Y: " << coord.getY()
//      << std::endl;
}

int Food::drawFood(GDPC* c){
  return GDPC_circle(c, coord.getX(), coord.getY(), (int)foodSize, true);
}

int Food::getFoodSize(){return (int)foodSize;}
Coordinates Food::getCoord(){return coord;}

