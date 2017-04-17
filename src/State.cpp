#include "State.h"
#include "Face.h"
#include "Sprite.h"
#include "Vector.h"
#include "InputManager.h"
#include "Camera.h"

State::State(){
  background = new Sprite();
  tile_set = new TileSet(64, 64, "tileset.png");
  tile_map = new TileMap("tileMap.txt", tile_set);
}

State::~State(){
  object_array.clear();
  delete tile_map;
  delete tile_set;
  delete background;
}

bool State::quit_requested(){
  return m_quit_requested;
}

void State::load_assets(){
  background->open("res/img/ocean.jpg");
}

void State::update(float delta){
  InputManager & inputManager = InputManager::get_instance();

  Camera::update(delta);

  if(inputManager.key_press(SDLK_ESCAPE) or inputManager.quit_requested()){
    m_quit_requested = true;
    return;
  }

  if(inputManager.key_press(SDLK_SPACE)){
    int x = inputManager.get_mouse_x() - Camera::pos.x;
    int y = inputManager.get_mouse_y() - Camera::pos.y;
    add_object(x, y);
  }

  for(auto p = object_array.begin(); p < object_array.end(); ++p){
    (*p)->update(delta);
    if((*p)->is_dead()){
      object_array.erase(p);
    }
  }
}

void State::render(){
  background->render(0, 0);
  tile_map->render(Camera::pos.x, Camera::pos.y);

  for(auto & go : object_array){
    go->render();
  }
}

void State::add_object(float mx, float my){
  float angle = 2 * 3.14159265358979 * (rand()%360) / 360;

  Vector vector(mx + 200, my);
  vector.rotate(Vector(mx, my), angle);

  object_array.emplace_back(new Face(vector.x, vector.y));
}
