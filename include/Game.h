#ifndef GAME_H
#define GAME_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <iostream>
#include <vector>

#include "State.h"

using std::string;

class Game{
private:
  static Game * instance;
  SDL_Window * window;
  SDL_Renderer * renderer = nullptr;
  State * state;

  int frame_start;
  float delta;

  void calculate_delta_time();

public:
  Game(string title, int width, int height);
  ~Game();

  SDL_Renderer * get_renderer();
  State & get_state();
  static Game & get_instance();
  void run();
  float get_delta_time();
};

#endif
