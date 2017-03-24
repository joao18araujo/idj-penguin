#include "Game.h"

Game::Game(string title, int width, int height){
  int sdl_init = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
  if(sdl_init){
    printf("%s\n", SDL_GetError());
  }

  int img_init = IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);
  if(img_init != IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF){
    printf("%s\n", SDL_GetError());
  }

  window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED, width, height, 0);
  if(window == nullptr){
    printf("%s\n", SDL_GetError());
  }

  renderer = SDL_CreateRenderer(-1);
  if(renderer == nullptr){
    printf("%s\n", SDL_GetError());
  }
}

Game::~Game(){
  IMG_Quit();
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void Game::run(){

}

Game & Game::get_instance(){
  return *instance;
}

State & Game::get_state(){
  return *state;
}

SDL_Renderer * get_renderer(){
  return renderer;
}
