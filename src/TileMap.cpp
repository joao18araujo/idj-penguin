#include "TileMap.h"

#include <fstream>

TileMap::TileMap(string file, TileSet * set) : tile_set(set){
  this.load(file);
}

int TileMap::get_width() const{
  return map_width;
}

int TileMap::get_height() const{
  return map_height;
}

int TileMap::get_depth() const{
  return map_depth;
}

void TileMap::set_tile_set(TileSet * set){
  tile_set = set;
}

void TileMap::load(string file){
  fstream tile_map(file);

  tile_map >> map_width;
  tile_map.ignore(256, ',');
  tile_map >> map_height;
  tile_map.ignore(256, ',');
  tile_map >> map_depth;
  tile_map.ignore(256, ',');

  tile_matrix.resize(map_width * map_height * map_depth);

  for(int i = 0; i < map_width; ++i){
    for(int j = 0; j < map_height; ++j){
      for(int k  = 0; k < map_depth; ++k){
        int tmp;
        tile_map >> tmp;
        tile_matrix[(i * map_height + j) * map_depth + k] = tmp - 1;
        printf("%d, %d, %d = %d\n", i, j, k, (i * map_height + j) * map_depth + k);
      }
    }
  }

}
int & TileMap::at(int x, int y, int z){
  return tile_matrix[(i * map_height + j) * map_depth + k];
}

void TileMap::render_layer(int layer, int camera_x, int camera_y){
  for(int i = 0; i < map_width; ++i){
    for(int j = 0; j < map_height; ++j){
      int index = this.at(i, j, layer);
      tile_set.render(index, camera_x, camera_y);
    }
  }
}

void TileMap::render(int camera_x, int camera_y){
  for(int k = 0; k < map_depth; ++k){
    this.render_layer(k, camera_x, camera_y);
  }
}
