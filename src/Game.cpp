#include "Game.h"

#include "InputManager.h"

#include <cstdlib>

Game * Game::instance = nullptr;

Game::Game(string title, int width, int height){
  instance = instance? instance : this;
  frame_start = SDL_GetTicks();
  delta = 0;

  srand(time(nullptr));

  int sdl_init = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
  if(sdl_init){
    printf("%s\n", SDL_GetError());
    exit(-1);
  }

  int img_flags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
  int img_init = IMG_Init(img_flags);
  if(img_init != img_flags){
    printf("%s\n", SDL_GetError());
    exit(-1);
  }

  window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED, width, height, 0);
  if(window == nullptr){
    printf("%s\n", SDL_GetError());
    exit(-1);
  }

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if(renderer == nullptr){
    printf("%s\n", SDL_GetError());
    exit(-1);
  }

  state = new State();
}

Game::~Game(){
  delete state;

  IMG_Quit();
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void Game::run(){
  this->calculate_delta_time();

  state->load_assets();
  while(state->quit_requested() == false){
    InputManager::get_instance().update();
    state->update(delta);
    state->render();

    SDL_RenderPresent(renderer);
    SDL_Delay(33);

  }
}

Game & Game::get_instance(){
  return *instance;
}

State & Game::get_state(){
  return *state;
}

SDL_Renderer * Game::get_renderer(){
  return renderer;
}

void Game::calculate_delta_time(){
  int new_frame_start = SDL_GetTicks();

  delta = (new_frame_start - frame_start)/100.0;

  frame_start = new_frame_start;
}

float Game::get_delta_time(){
  return delta;
}
