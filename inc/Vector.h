#ifndef VECTOR_H
#define VECTOR_H

class Vector{
public:
  Vector(float mx = 0, float my = 0);
  float get_x() const;
  float get_y() const;
  void rotate(Vector origin, float angle);

private:

  float x;
  float y;
};

#endif
