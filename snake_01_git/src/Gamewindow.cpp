/**
 * @file Gamewindow.cpp
 * @author Florian Leuze (3308288) <st155013@stud.uni-stuttgart.de>
 * @date 13.03.2018
 * @brief Brief description of the file
 */

#include "Gamewindow.h"

Gamewindow::Gamewindow(int w, int l) :
    coord(w, l) {
  canvas = GDPC_create(coord.getX(), coord.getY());
  if (canvas == NULL)
    exit(1);
  GDPC_title(canvas, "Snake");
}
Gamewindow::~Gamewindow() {
}

GDPC* Gamewindow::getGdpc() {
  return canvas;
}

Coordinates Gamewindow::getCoord() {
  return coord;
}

void Gamewindow::clearWindow() {
  GDPC_clear(canvas);
}

void Gamewindow::drawAll() {
  for (int i = 0; i <= coord.getX(); i += 5) {
    for (int j = 0; j <= coord.getY(); j += 5) {
      mSleep(1);
      GDPC_circle(canvas, i, j, 5, true);
    }
  }
}

int* Gamewindow::getMenu(){ return menu;}

void Gamewindow::setMenu(int m1, int m2){
  menu[0] = m1;
  menu[1] = m2;}

void Gamewindow::drawFrame(int pos, std::string text, bool t, int r, int g, int b) {
  GDPC_color(canvas, r, g, b);
  switch (pos) {
case 0:
  frameHelper(yFrame[0], r+g+b);
  if (t == true)
    GDPC_text(canvas, (coord.getX() / 2) / 3 + 5, (yFrame[0] + yFactor / 2), text.c_str());
  break;
case 1:
  frameHelper(yFrame[1], r+g+b);
  if (t == true)
    GDPC_text(canvas, (coord.getX() / 2) / 3 + 5, (yFrame[1] + yFactor / 2), text.c_str());
  break;
case 2:
  frameHelper(yFrame[2], r+g+b);
  if (t == true)
    GDPC_text(canvas, (coord.getX() / 2) / 3 + 5, (yFrame[2] + yFactor / 2), text.c_str());
  break;
case 3:
  frameHelper(yFrame[3], r+g+b);
  if (t == true)
    GDPC_text(canvas, (coord.getX() / 2) / 3 + 5, (yFrame[3] + yFactor / 2), text.c_str());
  break;
  }
}

void Gamewindow::frameHelper(int yStart, int rgb) {
  int xs = (coord.getX() / 2) / 3;
  int xe = (coord.getX() / 2) + 2 * ((coord.getX() / 2) / 3);
  if (rgb == 0)
    GDPC_color(canvas, 192, 192, 192);
  GDPC_linewidth(canvas, 3);
  GDPC_line(canvas, xs, yStart, xe, yStart);
  GDPC_line(canvas, xs, yStart, xs, (yStart + 35));
  GDPC_line(canvas, xs, (yStart + 35), xe, (yStart + 35));
  GDPC_line(canvas, xe, yStart, xe, (yStart + 35));
  if(rgb == 0)
    GDPC_color(canvas, 0, 0, 0);
}

void Gamewindow::changeColour(int r, int g, int b) {
  GDPC_color(canvas, r, g, b);
  GDPC_transform_area(canvas, 0, 0, coord.getX(), 18, 0, 0, SLOWFADE, MOVE);
}

