#ifndef ENDSTATE_H
#define ENDSTATE_H

#include "State.h"
#include "Sprite.h"
#include "Music.h"
#include "Text.h"
#include "StateData.h"
#include "Timer.h"

class EndState : public State {
private:
  Sprite background;
  Music music;
  Text * instruction;
  Timer timer;

public:
  EndState(StateData state_data);

  void update(float delta);
  void render();

  void pause();
  void resume();
};

#endif
