/**
 * @file Food.h
 * @author Florian Leuze (3308288) <st155013@stud.uni-stuttgart.de>
 * @date 13.03.2018
 * @brief Class Definition for Food Class
 */

#ifndef SRC_FOOD_H_
#define SRC_FOOD_H_

#include <time.h>
#include "gdptools.h"
#include "gdpc.h"
#include "Coordinates.h"
#include "Gamewindow.h"

/**
 * @brief Stores coordinates and size values of each food object. Can generate random Coordinates and draw food
 */
class Food {
private:
  Coordinates coord; /** Coordinate Object to store Position of the Food object*/
  double foodSize = 15; /** Dotsize value for the Food object*/
public:
  //CONSTRUCTORS/DECONSTRUCTORS/************************************************************/
  /**
   * @brief Generates a initialized Food object with no coordinates
   */
  Food();
  /**
   * @brief Create Food type object with x and y values
   * @param x value
   * @param y value
   */
  Food(int x, int y);
  /**
   * @brief Standard deconstructor
   */
  virtual ~Food();

  //COODRINATE-FUNCTIONS/DRAWING/************************************************************/
  /**
   * @brief Generates a random coordinate for the food using the mersenne algorithm from the gdptools
   * @param val Coordinate Values that should contain the Size of the Gamewindow
   * @param wd Gamewindow type Pointer that should point to the current Gamewindow
   */
  void generateCoordiantes(Coordinates val, Gamewindow* wd);
  /**
   * @brief Draws food on a gdpc object using the gdpc library
   * @param c Pointer to GDPC that serves as drawing area
   */
  int drawFood(GDPC* c);
  /**
   * @brief Returns the Size of the Food type object
   */
  int getFoodSize();
  /**
   * @brief Returns a Coordinate type object storing the coordinates of the Food type object
   */
  Coordinates getCoord();
  /**
   * @brief Standard deconstructor
   */
};

#endif /* SRC_FOOD_H_ */
