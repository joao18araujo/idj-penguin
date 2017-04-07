#include "Resources.h"

#include "Game.h"

unordered_map<string, SDL_Texture *> Resources::image_table;

SDL_Texture * Resources::get_image(string file){
  SDL_Texture * texture;
  if(image_table.find(file) == image_table.end()){
      texture =
        IMG_LoadTexture(Game::get_instance().get_renderer(), file.c_str());
      image_table.emplace(file, texture);
  }else{
    texture = image_table[file];
  }

  if(texture == nullptr){
    printf("%s: %s\n", SDL_GetError(), file.c_str());
    exit(-1);
  }

  return texture;
}

void Resources::clear_images(){
    for(auto & texture : image_table){
      SDL_DestroyTexture(texture.second);
    }

    image_table.clear();
}
