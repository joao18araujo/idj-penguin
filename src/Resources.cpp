#include "Resources.h"

#include "Game.h"

unordered_map<string, shared_ptr<SDL_Texture> > Resources::image_table;

shared_ptr<SDL_Texture> Resources::get_image(string file){

  if(image_table.find(file) == image_table.end()){
      SDL_Texture * tx =
             IMG_LoadTexture(Game::get_instance().get_renderer(), file.c_str());

      if(tx == nullptr){
       printf("%s: %s\n", SDL_GetError(), file.c_str());
       exit(-1);
      }

      shared_ptr<SDL_Texture> texture(tx,
                    [](SDL_Texture * txt) { SDL_DestroyTexture(txt); });

      image_table.emplace(file, texture);
  }

  return image_table[file];
}

void Resources::clear_images(){
  for(auto texture : image_table){
    if(texture.second.unique()){
      image_table.erase(texture.first);
    }
  }
}
