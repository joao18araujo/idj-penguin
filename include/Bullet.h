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
  string m_target;

public:

  Bullet(float x, float y, float angle, float speed, float max_distance, float frame_count, float frame_time, string sp, string ctarget);
  void update(float delta);
  void render();
  bool is_dead();

  void notify_collision(GameObject & object);
  bool is(string type);
  bool target(string ctarget);

};

#endif
