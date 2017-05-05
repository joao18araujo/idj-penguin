#include <iostream>

#include "Sprite.h"
#include "Game.h"
#include "Resources.h"

#define PI 3.14159265358979

Sprite::Sprite(){
  texture = nullptr;
  scale_x = scale_y = 1;
}

Sprite::Sprite(string file){
  texture = nullptr;
  open("res/img/" + file);
  scale_x = scale_y = 1;
}

Sprite::~Sprite(){
}

int Sprite::get_width(){
  return width * scale_x;
}

int Sprite::get_height(){
  return height * scale_y;
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

void Sprite::render(int x, int y, float angle){
  SDL_Rect dstrect = SDL_Rect{x, y, (int)(clip_rect.w * scale_x), (int)(clip_rect.h * scale_y)};

  angle *= (180 / PI);
  int render_copy = SDL_RenderCopyEx(Game::get_instance().get_renderer(), texture,
    &clip_rect, &dstrect, angle, nullptr, SDL_FLIP_NONE);
  if(render_copy){
    printf("%s\n", SDL_GetError());
    exit(-1);
  }
}

void Sprite::set_scale_x(float scale){
  scale_x = scale;
}

void Sprite::set_scale_y(float scale){
  scale_y = scale;
}
