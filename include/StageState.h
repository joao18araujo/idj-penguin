#ifndef STAGESTATE_H
#define STAGESTATE_H

#include "SDL2/SDL.h"

#include <iostream>
#include <vector>
#include <memory>

#include "State.h"
#include "GameObject.h"
#include "Sprite.h"
#include "TileSet.h"
#include "TileMap.h"
#include "Music.h"

using std::vector;
using std::unique_ptr;

class StageState : public State{
private:
  Sprite * background;
  TileSet * tile_set;
  TileMap * tile_map;
  Music * music;

public:
  StageState();
  ~StageState();

  void update(float delta);
  void render();

  void pause();
  void resume();

  void load_assets();
};

#endif
