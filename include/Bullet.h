#ifndef BULLET_H
#define BULLET_H

#include "Sprite.h"
#include "Vector.h"
#include "GameObject.h"

class Bullet : public GameObject{
private:

  Sprite sprite;
  Vector speed;
  float distance_left;
  float modular_speed;

public:

  Bullet(float x, float y, float angle, float speed, float max_distance, string sp);
  void update(float delta);
  void render();
  bool is_dead();
};

#endif
