#include "Rectangle.h"

Rectangle::Rectangle(){}

Rectangle::Rectangle(float ax, float ay, float w, float h) :
                     x(ax), y(ay), width(w), height(h){}

bool Rectangle::is_inside(float mx, float my){
  bool horizontal_in = (mx <= x - width/2 and mx >= x + width/2);
  bool vertical_in = (my <= y - height/2 and my >= y + height/2);

  return horizontal_in and vertical_in;
}
