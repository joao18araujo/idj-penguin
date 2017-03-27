#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <SDL2/SDL.h>

class Rectangle{
public:
  Rectangle();
  Rectangle(float x, float y, float width, float height);
  bool is_inside(float mx, float my);

private:

  float x;
  float y;
  float width;
  float height;
};

#endif
