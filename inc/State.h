#ifndef STATE_H
#define STATE_H

#ifdef _WIN32
#else
#include <SDL2/SDL.h>
#endif

#include <iostream>
#include <vector>
#include <memory>

#include "GameObject.h"
#include "Sprite.h"

using std::vector;
using std::unique_ptr;

class State{
private:
  Sprite * background;
  bool m_quit_requested = false;
  vector<unique_ptr<GameObject>> object_array;

public:
  State();
  ~State();

  bool quit_requested();
  void load_assets();
  void update(float delta);
  void render();
  void input();
  void add_object(float mouse_x, float mouse_y);
};

#endif
