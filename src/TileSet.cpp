#include "TileSet.h"

TileSet::TileSet(int width, int height, string file) :
        tile_set(file), tile_width(width), tile_height(height){
  rows = tile_set.get_height() / tile_height;
  columns = tile_set.get_width() / tile_width;
}

void TileSet::render(int index, int x, int y){
  if(index >= 0 and index <= rows * columns - 1){
    int cx = (index%columns) * tile_height;
    int cy = (index/columns) * tile_width;
    tile_set.set_clip(cx, cy, tile_width, tile_height);
    tile_set.render(x, y);
  }
}

int TileSet::get_tile_width() const{
  return tile_width;
}

int TileSet::get_tile_height() const{
  return tile_height;
}
