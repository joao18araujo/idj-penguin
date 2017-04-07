#ifndef TILESET_H
#define TILESET_H

#include "Sprite.h"

class TileSet{
private:
  Sprite tile_set;
  int rows;
  int columns;
  int tile_width;
  int tile_height;

public:
  TileSet(int width, int height, string file);
  void render(unsigned index, float x, float y);
  int get_tile_width() const;
  int get_tile_height() const;
};

#endif
