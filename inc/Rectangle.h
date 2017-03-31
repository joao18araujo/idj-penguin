#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <SDL2/SDL.h>

class Rectangle{
public:
  Rectangle();
  Rectangle(float x, float y, float width, float height);
  bool is_inside(float mx, float my);
  float get_x() const;
  float get_y() const;
  float get_draw_x() const;
  float get_draw_y() const;
  float get_width() const;
  float get_height() const;

private:

  float x;
  float y;
  float width;
  float height;
};

#endif
