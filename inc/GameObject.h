#include "Rectangle.h"

class GameObject{
public:
  virtual ~GameObject(){};
  virtual void update(float delta) = 0;
  virtual void render() = 0;
  virtual bool is_dead() = 0;

  Rectangle box;
};
