#include "Resources.h"

#include "Game.h"

unordered_map<string, SDL_Texture *> Resources::image_table;

SDL_Texture * Resources::get_image(string file){
  SDL_Texture * texture;
  if(image_table.find(file) == image_table.end()){
      image_table[file] =
        IMG_LoadTexture(Game::get_instance().get_renderer(), file.c_str());
  }

  if(texture == nullptr){
    printf("%s\n", SDL_GetError());
    exit(-1);
  }
}

void Resources::clear_images(){
    for(auto & texture : image_table){
      SDL_DestroyTexture(texture.second);
    }

    image_table.clear();
}
