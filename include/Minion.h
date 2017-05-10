#ifndef MINION_H
#define MINION_H

#include "GameObject.h"
#include "Sprite.h"
#include "Vector.h"

class Minion : public GameObject{
private:

  GameObject * center;
  Sprite sprite;
  float arc;

public:

  Minion();
  Minion(GameObject * minion_center, float arc_offset = 0, float scale = 1);

  void update(float delta);
  void render();
  bool is_dead();
  void shoot(Vector pos);
  float distance(Vector pos);

  void notify_collision(GameObject & object);
  bool is(string type);
};

#endif
