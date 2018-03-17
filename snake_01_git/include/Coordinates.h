/**
 * @file Coordinates.h
 * @author Florian Leuze (3308288) <st155013@stud.uni-stuttgart.de>
 * @date 13.03.2018
 * @brief Class Definition for Coordinates Class
 */

#ifndef SRC_COORDINATES_H_
#define SRC_COORDINATES_H_

#include <iostream>
#include <unistd.h>
/**
 * @brief Stores 2-dimensional Coordinate values
 * Contains following private Members:
 * int posX - Stores X Position
 * int posY - Stores Y Position
 */
class Coordinates {
private:
  int posX; /**X-Position*/
  int posY; /**Y-Position*/
public:
  //CONSTRUCTORS/DECONSTRUCTORS/************************************************************/
  /**
   * @brief Creates a empty Coordinate type object with x and y values
   */
  Coordinates();
  /**
   * @brief Create a Coordinate type object with x and y values
   * @param x value
   * @param y value
   */
  Coordinates(int x, int y);

  //SETTERS/************************************************************/
  /**
   * @brief Set the x Value
   * @param x Value
   */
  int setX(int x);
  /**
   * @brief Set the y Value
   * @param Y Value
   */
  int setY(int Y);

  //GETTERS/************************************************************/
  /**
   * @brief Get the x Value
   */
  int getX();
  /**
   * @brief Get the y Value
   */
  int getY();

  //COORDINATE-FUNCTIONS/************************************************************/
  /**
   * @brief Simply prints the coordinates to stdout.
   */
  void printCoord();
  /**
   * @brief Makes sure the Coordinates wont conflict with the borders of the Gamewindow (used only in food so far)
   */
  void fixCoordinates(Coordinates wd, int size);
};

#endif /* SRC_COORDINATES_H_ */
