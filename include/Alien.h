#ifndef ALIEN_H
#define ALIEN_H

#include <queue>
#include <vector>

#include "GameObject.h"
#include "Sprite.h"
#include "Vector.h"
#include "Minion.h"
#include "Timer.h"


using std::queue;
using std::vector;

#define LAYER 0

class Alien : public GameObject{
private:

  // class Action{
  // public:
  //   enum ActionType {MOVE, SHOOT};
  //
  //   ActionType type;
  //   Vector pos;
  // };

  Sprite sprite;
  Vector speed;
  int hp;

  // queue<Action> task_queue;
  vector<Minion> minion_array;

  bool arrived(Vector pos);

  enum AlienState {MOVING, RESTING};
  AlienState state;
  Timer rest_timer;
  float cooldown;
  Vector destination;

public:

  Alien(float x, float y, int n_minions);
  ~Alien();

  void update(float delta);
  void render();
  bool is_dead();

  void notify_collision(GameObject & object);
  bool is(string type);
  void shoot();

  static int alien_count;
};

#endif
