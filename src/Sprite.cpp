#include <iostream>

#include "Sprite.h"
#include "Game.h"
#include "Resources.h"

Sprite::Sprite(){
  texture = nullptr;
}

Sprite::Sprite(string file){
  texture = nullptr;
  open("res/img/" + file);
}

Sprite::~Sprite(){
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
  texture = Resources::get_image(file);

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
