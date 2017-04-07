#ifndef FACE_H
#define FACE_H

#include "GameObject.h"
#include "Sprite.h"

class Face : public GameObject{
private:
  int hitpoints;
  Sprite sprite;
  
public:
  Face(float x, float y);

  ~Face();
  void update(float delta);
  void render();
  bool is_dead();

  void take_damage(int damage);
};

#endif
