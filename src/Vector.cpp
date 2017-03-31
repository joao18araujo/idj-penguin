#include "Vector.h"
#include <cmath>

Vector::Vector(float mx, float my) : x(mx), y(my){}

float Vector::get_x() const{
  return x;
}

float Vector::get_y() const{
  return y;
}

void Vector::rotate(Vector origin, float angle){

  x = origin.get_x() + 200 * cos(angle);
  y = origin.get_y() + 200 * sin(angle);
}
