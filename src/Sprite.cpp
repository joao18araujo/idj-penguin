#include <iostream>

#include "Sprite.h"
#include "Game.h"

Sprite::Sprite(){
  texture = nullptr;
}

Sprite::Sprite(string file){
  printf("in22\n");
  texture = nullptr;
  open("res/img/" + file);
  printf("in223\n");
}

Sprite::~Sprite(){
  if(texture){
    SDL_DestroyTexture(texture);
  }
}

int Sprite::get_width(){
  return width;
}

int Sprite::get_height(){
  return height;
}

bool Sprite::is_open(){
  return texture != nullptr;
}

void Sprite::open(string file){
  printf("in open %s\n", file.c_str());
  texture = IMG_LoadTexture(Game::get_instance().get_renderer(), file.c_str());
  printf("out open\n");
  if(texture == nullptr){
    printf("%s\n", SDL_GetError());
    exit(-1);
  }

  int query_texture = SDL_QueryTexture(texture, nullptr, nullptr,
    &width, &height);
  if(query_texture){
    printf("%s\n", SDL_GetError());
    exit(-1);
  }

  set_clip(0, 0, width, height);
}

void Sprite::set_clip(int x, int y, int w, int h){
  clip_rect = SDL_Rect{x, y, w, h};
}

void Sprite::render(int x, int y){
  SDL_Rect dstrect = SDL_Rect{x, y, clip_rect.w, clip_rect.h};

  int render_copy = SDL_RenderCopy(Game::get_instance().get_renderer(), texture,
    &clip_rect, &dstrect);
  if(render_copy){
    printf("%s\n", SDL_GetError());
    exit(-1);
  }
}
