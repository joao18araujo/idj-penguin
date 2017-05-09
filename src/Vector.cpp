#include "Vector.h"
#include <cmath>

Vector::Vector(float mx, float my) : x(mx), y(my){}

void Vector::rotate(Vector origin, float angle){
  x = origin.x + 200 * cos(angle);
  y = origin.y + 200 * sin(angle);
}

void Vector::transform(float module, float angle){
  x = module * cos(angle);
  y = module * sin(angle);
}
