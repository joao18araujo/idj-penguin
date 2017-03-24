#include "GameObject.h"
#include "Sprite.h"

class Face : public GameObject{
public:
  Face(float x, float y);

  ~Face();
  void update(float delta);
  void render();
  bool is_dead();

  void take_damage(int damage);

private:
  int hitpoints;
  Sprite sprite;
};
