/**
 * @file Snakepart.h
 * @author Florian Leuze (3308288) <st155013@stud.uni-stuttgart.de>
 * @date 13.03.2018
 * @brief Class Definition of Snakepart Class
 */

#ifndef SRC_SNAKEPART_H_
#define SRC_SNAKEPART_H_
#include <list>
#include <cmath>
#include "Coordinates.h"
#include "Gamewindow.h"
#include "Food.h"
#include "gdpc.h"
/**
 * @brief Stores the direction value. Possible directions are
 * @param STOP Represents the value 0, no movement
 * @param LEFT Represents the value 1, movement to the left
 * @param RIGHT Represents the value 2, movement to the right
 * @param UP Represents the value 3, movement up
 * @param DOWN Represents the value 4, movement down
 */
enum eDirection {
  STOP = 0, LEFT, RIGHT, UP, DOWN
};

/**
 * @brief Stores all values needed to define each snakeparts including old and new Coordinate objects,
 * direction (enum eDirection) and sizes of each Snakepart.
 */
class Snakepart {
private:
  int number;
  double snakeSize = 30;
  Coordinates coord, coordOld;
  bool first;
  eDirection dir;
  std::list<Snakepart> *s;
public:
  //CONSTRUCTORS/DECONSTRUCTORS/************************************************************/
  /**
   * @brief Standard Constructor will initialize all Members and set all of them to 0 or NULL. Be careful, also the std::list
   * will be set to NULL! C
   */
  Snakepart();

  /**
   * @brief Will initialize all Members and set all of them to 0 except for the std::list.
   * @param *p This address will be stored in the std::list Member
   */
  Snakepart(std::list<Snakepart> *p);

  /**
   * @brief This should be used to add more Snakeparts to an existing snake (and therefore to the existing list).
   * The function will store the address in param 2 into the std::list pointer Member. It will check if the list in param 1 is
   * not empty and if so it will take the old Coordinate values of last member of the list and uses these as new Coordinate
   * values for the new Snakepart.
   * @param sn This is a copy of the snakelist. Should be updated to just use the pointer since this doesnt makes sense.
   * @param *p This address will be stored in the std::list Member
   */
  Snakepart(std::list<Snakepart> sn, std::list<Snakepart> *p);

  /**
   * @brief Just a standard deconstructor so far.
   */
  virtual ~Snakepart();

  //GETTERS/************************************************************/
  /**
   * @brief Returns the X position
   */
  int getPosX();
  /**
   * @brief Returns the Y position
   */
  int getPosY();
  /**
   * @brief Returns the old X position
   */
  int getOldPosX();
  /**
   * @brief Returns the old Y position
   */
  int getOldPosY();
  /**
   * @brief Returns the number of the Snakepart
   */
  int getNumber();
  /**
   * @brief Returns the direction as eDirection enum
   */
  eDirection getDir();
  /**
   * @brief Returns the true or false value (if its the leading Snakepart the value will be true)
   */
  bool isFirst();

  //SETTERS/************************************************************/
  /**
   * @brief Returns integer Value for Error handling (not yet implemented), sets X Value
   * @param coordinate Integer Value
   */
  int setPosX(int coordinate);
  /**
   * @brief Returns integer Value for Error handling (not yet implemented), sets Y Value
   * @param coordinate Integer Value
   */
  int setPosY(int coordinate);
  /**
   * @brief Returns integer Value for Error handling (not yet implemented), sets both Coordinate Values
   * @param y Integer Value for y
   * @param x Integer Value for x
   */
  int setPosXY(int y, int x);
  /**
   * @brief Returns integer Value for Error handling (not yet implemented), sets old X Value
   * @param oldCoordinate Integer Value
   */
  int setOldPosX(int oldCoordinate);
  /**
   * @brief Returns integer Value for Error handling (not yet implemented), sets old Y Value
   * @param oldCoordinate Integer Value
   */
  int setOldPosY(int oldCoordinate);
  /**
   * @brief Returns integer Value for Error handling (not yet implemented), sets both old Coordinate Values
   * @param oldY Integer Value for old y
   * @param oldX Integer Value for old x
   */
  int setOldPosXY(int oldY, int oldX);
  /**
   * @brief Returns integer Value for Error handling (not yet implemented), sets the number
   * @param n Integer value
   */
  int setNumber(int n);
  /**
   * @brief Returns integer Value for Error handling (not yet implemented). Sets first value
   * @param f Bool Value (if true then this is the first Snakepart. There cannot be more than
   * one first Snakeparts)
   */
  int setFirst(bool f);

  //OTHERS/************************************************************/
  /**
   * @brief Just a helper function for debugging that prints information about every member of the list
   */
  void browseList();
  /**
   * @brief Resets the whole object
   */
  void resetEverything();

  //MOVEMENT/DRAWING/************************************************************/
  /**
   * @brief Draws the specific Snakepart, returns integer value for error handling (not yet implemented though)
   * @param wd Gamewindow pointer
   * @param food Food pointer
   */
  int drawWorm(Gamewindow* wd, Food* food);
  /**
   * @brief Function to realise the movement of each Snakepart. Calls drawWorm itself.
   * Returns new Coordinate object for each Snakepart.
   * @param wd Gamewindow pointer
   * @param d eDirection type to store the direction of the Snakepart
   * @param food Food pointer
   */
  Coordinates moveWorm(Gamewindow* wd, eDirection d, Food* food);
  /**
   * @brief Function to realise the movement of each Snakepart. Calls drawWorm itself.
   * Returns new Coordinate object for each Snakepart.
   * @param wd Gamewindow pointer
   * @param food Food pointer
   */
  Coordinates moveWorm(Gamewindow* wd, Food* food);
  /**
   * @brief Stores the values of the Coordinates type object at the address of a in the
   * Coordinates type object at the address of b.
   * @param &a Coordinate type object
   * @param &b Coordinate type object
   */
  void exchCoord(Coordinates &a, Coordinates &b);
  /**
   * @brief Function to make each Snakepart follows the next one. Not used anymore therefore not well documented
   */
  void followLast(std::list<Snakepart> s);
  /**
   * @brief Function to make each Snakepart follows the next one. Not used anymore therefore not well documented
   */
  void followLast(Snakepart *a, Snakepart *b);
  /**
   * @brief Handles the complete follow up process of each Snakepart. Gets all needed information from the std::list member
   */
  void followLast();
  /**
   * @brief Handles moving Snakeparts that hit a corner to the opposite edge and
   * stores the previously new Coordinates before moving the Snakepart in the old Coordinate object
   * @param &n Coordinate type object (New Coordinate)
   * @param &o Coordinate type object (Old Coordinate)
   * @param wd Gamewindow pointer
   */
  void fixCoord(Coordinates &n, Coordinates &o, Gamewindow* wd);
  //eating and other cool stuff
  /**
   * @brief Handles collision with Food type objects as well as with Snakeparts. Will cleanly destroy an eaten
   * Food type object and immediately spawn a new one at randomised Coordiantes. Will return a pointer to the old Food type
   * object if there was no collision. Will return a pointer to the new Food type object if a new one was created. Will return NULL
   * if a Snakepart was bitten and therefore the game is over.
   * @param wd Gamewindow type pointer
   * @param f Food type pointer
   */
  Food* collision(Gamewindow* wd, Food* f);
};

#endif /* SRC_SNAKEPART_H_ */
