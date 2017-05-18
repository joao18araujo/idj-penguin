#include "Text.h"

#include "Game.h"
#include "Resources.h"

#define SOLID Text::TextStyle::SOLID
#define SHADED Text::TextStyle::SHADED
#define BLENDED Text::TextStyle::BLENDED

Text::Text(string cfont_file, int cfont_size, TextStyle cstyle, string ctext, SDL_Color ccolor, int x, int y){
  open(cfont_file, cfont_size);
  font_size = cfont_size;
  style = cstyle;
  text = ctext;
  color = ccolor;
  box.set_x(x);
  box.set_y(y);
  texture = nullptr;
  remake_texture();
}

Text::~Text(){
  if(texture != nullptr){
    SDL_DestroyTexture(texture);
  }
}

void Text::render(int camera_x, int camera_y){
  SDL_Rect dstrect = SDL_Rect{camera_x, camera_y, clip_rect.w, clip_rect.h};

  int render_copy = SDL_RenderCopy(Game::get_instance().get_renderer(), texture,
    &clip_rect, &dstrect);
  if(render_copy){
      printf("Render: %s\n", SDL_GetError());
      exit(-1);
    }
}

void Text::set_pos(int x, int y, bool center_x, bool center_y){
  box.set_x(x - (center_x ? clip_rect.w * 0.5 : 0));
  box.set_y(y - (center_y ? clip_rect.h * 0.5 : 0));
}


void Text::set_text(string ctext){
  text = ctext;
  remake_texture();
}

void Text::set_color(SDL_Color ccolor){
  color = ccolor;
  remake_texture();
}

void Text::set_style(TextStyle cstyle){
  style = cstyle;
  remake_texture();
}

void Text::set_font_size(int cfont_size){
  font_size = cfont_size;
  remake_texture();
}

void Text::remake_texture(){
  if(texture != nullptr){
    SDL_DestroyTexture(texture);
  }

  switch(style){
    case SOLID:

    break;
    case SHADED:

    break;
    case BLENDED:

    break;
  }
}

void Text::open(string file, int size){
  font = Resources::get_font("res/font/" + file, size);
}
