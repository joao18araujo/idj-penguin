#include <SDL2/SDL.h>
#include <iostream>

class Sprite;

class State{
public:
  State();

  bool quit_requested();
  void load_assets();
  void update(float delta);
  void render();

private:
  Sprite * background;
  bool m_quit_requested = false;
};
