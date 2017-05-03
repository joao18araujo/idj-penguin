#ifndef ALIEN_H
#define ALIEN_H

#include <queue>
#include <vector>

#include "GameObject.h"
#include "Sprite.h"
#include "Vector.h"

using std::queue;
using std::vector;

class Alien : public GameObject{
private:

  class Action{
    typedef enum _ActionType {MOVE, SHOOT} ActionType;

    Action(ActionType type, float x, float y);
    ActionType type;
    Vector pos;
  };

  Sprite sprite;
  Vector speed;
  int hp;

  queue<Action> task_queue;
  vector<Minion> minion_array;

public:

  Alien(float x, float y, int n_minions);
  ~Alien();

  void update(float delta);
  void render();
  bool is_dead();
};

#endif
