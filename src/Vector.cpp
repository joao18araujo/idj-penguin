#include "Vector.h"
#include <cmath>

Vector::Vector(float mx, float my) : x(mx), y(my){}

void Vector::rotate(Vector origin, float angle){
  x = origin.x + 200 * cos(angle);
  y = origin.y + 200 * sin(angle);
}

Vector operator+(Vector v1, Vector v2){
  return Vector(v1.x + v2.x, v1.y + v2.y);
}
