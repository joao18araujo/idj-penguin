#include <SDL2/SDL.h>

class Rectangle{
public:
  Rectangle();
  Rectangle(float x, float y, float width, float height);

  float x;
  float y;
  float width;
  float height;
};
