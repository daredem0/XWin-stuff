/**
 * @file smallFunctions.cpp
 * @author Florian Leuze (3308288) <st155013@stud.uni-stuttgart.de>
 * @date 14.03.2018
 * @brief Brief description of the file
 */
#include "smallFunctions.h"

int mSleep(int milli) {
  struct timespec ts;
  ts.tv_sec = milli / 1000;
  ts.tv_nsec = milli * pow(10, 6);
  nanosleep(&ts, NULL);
  return 0;
}

