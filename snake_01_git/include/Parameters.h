/**
 * @file Parameters.h
 * @author Florian Leuze (3308288) <st155013@stud.uni-stuttgart.de>
 * @date 13.03.2018
 * @brief Class Definition for Parameter Class
 */

#ifndef SRC_PARAMETERS_H_
#define SRC_PARAMETERS_H_
#include "Gamewindow.h"
#include "Snakepart.h"
#include "Food.h"
#include "gdpc.h"
/**
 * @brief Stores multiple values which could be needed in different classes. This is kinda dirty but it work.
 * Stored values are for now:
 * GDPC*
 * Gamewindow*
 * Snakepart*
 * Food*
 * dotSize (garbage)
 * lock (to make sure the Parameters cannot be loaded before resetting the game)
 */
class Parameters {
private:
  GDPC* canvas;
  Gamewindow* window;
  Snakepart* snake;
  Food* food;
  int dotSize;
  bool lock;
  int score = 0;
public:
  //CONSTRUCTORS/DECONSTRUCTORS/************************************************************/
  Parameters();
  /**
   * @brief Initialize the Parameters
   * @param c GDPC pointer to the GDPC
   * @param w Gamewindow pointer to the Gamewindow
   * @param s Snakepart pointer to the Snakepart
   * @param f Food pointer to each Food object
   * @param d dotSize (not used anymore)
   */
  int loadParameters(GDPC* c, Gamewindow* w, Snakepart* s, Food* f, int d);
  /**
   * @brief Extra setter for new Food object in case of destruction of the old one
   * @param f Food type pointer to the new Food type object
   */
  //SETTERS/************************************************************/
  void setFood(Food* f);
  /**
   * @brief sets the new score
   * @param s Integer value containing the score (aka number of Snakeparts before dying).
   */
  void setScore(int s);

  //GETTERS/************************************************************/
  /**
   * @brief Returns the current Score.
   */
  int getScore();
  /**
   * @brief Returns GDPC pointer
   */
  GDPC* getGdpc();
  /**
   * @brief Returns Dot Size
   */
  int getDotSize();
  /**
   * @brief Returns Gamewindow pointer
   */
  Gamewindow* getGameWindow();
  /**
   * @brief Returns Snakepart pointer
   */
  Snakepart* getSnake();
  /**
   * @brief Returns Food pointer
   */
  Food* getFood();
  /**
   * @brief Tries to reset all parameters although there is a try/catch included use with causion. Bad things might happen.
   */

  //OTHERS/************************************************************/
  int resetPar();
};

#endif /* SRC_PARAMETERS_H_ */
