/**
 * @file Gamewindow.h
 * @author Florian Leuze (3308288) <st155013@stud.uni-stuttgart.de>
 * @date 13.03.2018
 * @brief Class Definition for Gamewindow Class
 */

#ifndef SRC_GAMEWINDOW_H_
#define SRC_GAMEWINDOW_H_

#include <stdlib.h>
#include "gdpc.h"
#include "Coordinates.h"
#include "gdpc.h"
#include "smallFunctions.h"

/**
 * @brief Stores gdpc and size for the Gamewindow. Can clear the Window, draw it completely for debugging
 * and return stored values
 */
class Gamewindow {
private:
  Coordinates coord;
  GDPC* canvas;
  int yFrame[4] = { 5, 40, 75, 110 };
  //int menu[4] = {0, 1, 2, 3};
  int menu[2];
  int yFactor = 23;
  void frameHelper(int yStart, int rgb);
public:
  //CONSTRUCTORS/DECONSTRUCTORS/************************************************************/
  /**
   * @brief Create Gamewindow type object with values for the field size (x, y values)
   */
  Gamewindow(int w, int l);
  /**
   * @brief Standard deconstructor
   */
  virtual ~Gamewindow();

  //GETTERS/************************************************************/
  /**
   * @brief Returns a GDPC type pointer to the gpdc where the gamewindow is created upon
   */
  GDPC* getGdpc();
  /**
   * @brief Returnes a Coordinates type object with the stored field-sizes
   */
  Coordinates getCoord();
  /**
   * @brief Returns pointer to menu array
   */
  int* getMenu();
  /**
   * @brief Sets both values of the Menu array. The first value is used to store the current button.
   * @param m1 Integer value that will be stored in menu[0], stores the current button
   * @param m2 Integer value that will be stored in menu[1]. Default parameter = 0; 1 means the Enter buttonw as hit.
   */

  //SETTERS/************************************************************/
  void setMenu(int m1, int m2 = 0);
  /**
   * @brief Clears the whole Gamewindow
   */

  //WINDOW/DRAWING/************************************************************/
  void clearWindow();

  //Debugging
  /**
   * @brief Draws out the whole window pixel for pixel (fast machines might need to make it a little slower)
   */
  void drawAll();

  //Menu Functions
  /**
   * @brief Will draw a menu frame on the specified position (0-4). In this frame the text stored in std::string text
   * will be written if t is true. The color can be specified by rgb valus. The defaults are each 0 for a black colour.
   * @param pos Integer value that specifies the position of the frame.
   * @param text std::string that contains the text that has to be written.
   * @param t Bool value. True -> text will be written; false -> text won't be written.
   * @param r Integer value for red
   * @param g Integer value for green
   * @param b Integer value for blue
   */
  void drawFrame(int pos, std::string text, bool t, int r = 0, int g = 0,
      int b = 0);
  /**
   * @brief Can be used to change the color of the gdpc of the gamewindow. Not used.
   * @param r Integer value for red
   * @param g Integer value for green
   * @param b Integer value for blue
   */
  void changeColour(int r, int g, int b);

  /**
   * @brief Just a standard Deconstructor
   */
};

#endif /* SRC_GAMEWINDOW_H_ */
