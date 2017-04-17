#include <iostream>
#include <vector>

#include "TileSet.h"
#include "Vector.h"

using std::vector;
using std::string;

class TileMap{
private:
  int map_width;
  int map_height;
  int map_depth;
  TileSet * tile_set;
  vector<int> tile_matrix;

public:
  TileMap(string file, TileSet * set);

  int get_width() const;
  int get_height() const;
  int get_depth() const;
  void set_tile_set(TileSet * set);

  void load(string file);
  int & at(int x, int y, int z = 0);
  void render_layer(int layer, Vector * camera_position);
  void render(int first, int last, Vector * camera_position);
};
