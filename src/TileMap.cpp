#include "TileMap.h"

#include <unistd.h>

#include <fstream>

using std::fstream;

TileMap::TileMap(string file, TileSet * set) : tile_set(set){
  this->load(file);
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
  printf("Loading...\n");

  fstream tile_map("res/map/" + file);

  tile_map >> map_width;
  tile_map.ignore(256, ',');
  tile_map >> map_height;
  tile_map.ignore(256, ',');
  tile_map >> map_depth;
  tile_map.ignore(256, ',');

  printf("%d %d %d\n", map_width, map_height, map_depth);

  tile_matrix.resize(map_width * map_height * map_depth);

  for(int i  = 0; i < map_depth; ++i){
    for(int j = 0; j < map_width; ++j){
      for(int k = 0; k < map_height; ++k){
        int tmp;
        tile_map >> tmp;
        tile_map.ignore(256, ',');
        tile_matrix[(i * map_width + j) * map_height + k] = tmp - 1;
        printf("%d, %d, %d = %d [%d]\n", i, j, k, tile_matrix[(i * map_width + j) * map_height + k],(i * map_width + j) * map_height + k);
      }
    }
  }

  printf("Loaded\n");
}
int & TileMap::at(int x, int y, int z){
  return tile_matrix[(x * map_width + y) * map_height + z];
}

void TileMap::render_layer(int layer, int camera_x, int camera_y){
  for(int j = 0; j < map_width; ++j){
    for(int k = 0; k < map_height; ++k){
      int index = this->at(layer, j, k);
      int x = camera_x + k * tile_set->get_tile_height();
      int y = camera_y + j * tile_set->get_tile_width();
      printf("Rendering in %d (%d, %d) %d %d\n", index, j, k, x, y);

      tile_set->render(index, x, y);
    }
  }
}

void TileMap::render(int camera_x, int camera_y){
  for(int i = 0; i < map_depth; ++i){
    this->render_layer(i, camera_x, camera_y);
  }
}
