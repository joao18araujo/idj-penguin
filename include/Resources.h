#ifndef RESOURCES_H
#define RESOURCES_H

#include "SDL2/SDL_image.h"

#include <iostream>
#include <unordered_map>
#include <memory>

using std::unordered_map;
using std::string;
using std::shared_ptr;

class Resources{
  static unordered_map<string, shared_ptr<SDL_Texture> > image_table;
private:

public:
  static shared_ptr<SDL_Texture> get_image(string file);
  static void clear_images();
};

#endif
