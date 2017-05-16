#ifndef TITLESTATE_H
#define TITLESTATE_H

#include "State.h"
#include "Sprite.h"

class TitleState : public State{
private:
  Sprite background;

public:
  TitleState();

  void update(float delta);
  void render();

  void pause();
  void resume();
};

#endif
