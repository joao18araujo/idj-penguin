#ifndef SPRITE_H
#define SPRITE_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <iostream>

using std::string;

class Sprite{
private:
  SDL_Texture * texture = nullptr;
  int width;
  int height;
  SDL_Rect clip_rect;
  float scale_x;
  float scale_y;

public:
  Sprite();
  Sprite(string file);
  ~Sprite();

  int get_width();
  int get_height();
  bool is_open();

  void open(string file);
  void set_clip(int x, int y, int w, int h);
  void render(int x, int y, float angle = 0);

  void set_scale_x(float scale);
  void set_scale_y(float scale);

};

#endif
