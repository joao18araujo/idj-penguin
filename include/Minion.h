#ifndef MINION_H
#define MINION_H

#include "GameObject.h"

class Minion{
private:

  GameObject * center;
  Sprite sprite;
  float arc;

public:

  Minion(GameObject * minion_center, float arc_offset = 0);

  void update(float delta);
  void render();
  void is_dead();
  void shoot(Vector pos);
};

#endif
