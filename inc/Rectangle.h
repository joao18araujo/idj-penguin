#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <SDL2/SDL.h>

class Rectangle{
public:
  Rectangle();
  Rectangle(float x, float y, float width, float height);
  bool is_inside(float mx, float my);
  float get_x();
  float get_y();
  float get_draw_x();
  float get_draw_y();
  float get_width();
  float get_height();

private:

  float x;
  float y;
  float width;
  float height;
};

#endif
