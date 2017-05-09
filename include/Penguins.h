#ifndef PENGUINS_H
#define PENGUINS_H

#include "GameObject.h"
#include "Sprite.h"
#include "Vector.h"

class Penguins : public GameObject{
private:
  Sprite body_sprite;
  Sprite cannon_sprite;
  Vector speed;
  float linear_speed;
  float cannon_angle;
  int hp;

public:
  Penguins(float x, float y);
  ~Penguins();

  void update(float delta);
  void render();
  bool is_dead();

  void shoot();

  static Penguins * player;
};

#endif
