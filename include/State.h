#ifndef STATE_H
#define STATE_H

#include "SDL2/SDL.h"

#include <iostream>
#include <vector>
#include <memory>

#include "GameObject.h"
#include "Sprite.h"
#include "TileSet.h"
#include "TileMap.h"

using std::vector;
using std::unique_ptr;

class State{
private:
  Sprite * background;
  bool m_quit_requested = false;
  vector<unique_ptr<GameObject>> object_array;
  TileSet * tile_set;
  TileMap * tile_map;

public:
  State();
  ~State();

  bool quit_requested();
  void load_assets();
  void update(float delta);
  void render();
  void add_object(float mouse_x, float mouse_y);
  void add_object(GameObject * ptr);
};

#endif
