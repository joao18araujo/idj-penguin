#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "State.h"

using std::string;

class Game{
public:
  Game(string title, int width, int height);
  ~Game();

  SDL_Renderer * get_renderer();
  State & get_state();
  static Game & get_instance();
  void run();

private:
  static Game * instance;
  SDL_Window * window;
  SDL_Renderer * renderer = nullptr;
  State * state;
};
