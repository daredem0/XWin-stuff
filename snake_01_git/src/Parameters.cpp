/**
 * @file Parameters.cpp
 * @author Florian Leuze (3308288) <st155013@stud.uni-stuttgart.de>
 * @date 13.03.2018
 * @brief Brief description of the file
 */

#include "Parameters.h"

Parameters::Parameters() {
  lock = false;
  canvas = NULL;
  window = NULL;
  snake = NULL;
  food = NULL;
  dotSize = 0;
}

int Parameters::loadParameters(GDPC* c, Gamewindow* w, Snakepart* s, Food* f,
    int d) {
  if (lock == false) {
    canvas = c;
    window = w;
    snake = s;
    food = f;
    dotSize = d;
    lock = true;
    return 0;
  } else
    return 1;
}

void Parameters::setFood(Food* f) {
  food = f;
}

void Parameters::setScore(int s) {
  score = s;
}
int Parameters::getScore() {
  return score;
}

GDPC* Parameters::getGdpc() {
  return canvas;
}

int Parameters::getDotSize() {
  return dotSize;
}

Gamewindow* Parameters::getGameWindow() {
  return window;
}

Snakepart* Parameters::getSnake() {
  return snake;
}

Food* Parameters::getFood() {
  return food;
}

int Parameters::resetPar() {
  try
  {
  lock = false;
  canvas = NULL;
  window = NULL;
  snake = NULL;
  food = NULL;
  dotSize = 0;
  }
  catch(...) {
  }
  std::cout << "Resetpar survived" << std::endl;
  return 0;
}

