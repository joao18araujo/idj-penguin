#ifndef COLLISION_H
#define COLLISION_H

#include <cmath>
#include <algorithm>

#include "Rectangle.h"
#include "Vector.h"

class Collision {
public:
  static inline bool is_colliding(Rectangle& a, Rectangle& b, float angleOfA, float angleOfB);

private:
  static inline float mag(const Vector& p);
  static inline Vector norm(const Vector& p);
  static inline float dot(const Vector& a, const Vector& b);
  static inline Vector rotate(const Vector& p, float angle);
};

#endif
