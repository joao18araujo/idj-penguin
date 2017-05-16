#include "StageState.h"

#include "Face.h"
#include "Sprite.h"
#include "Vector.h"
#include "Game.h"
#include "InputManager.h"
#include "Camera.h"
#include "Alien.h"
#include "Penguins.h"
#include "Collision.h"
#include "TitleState.h"

#include <ctime>

#define LAYER 0

StageState::StageState(){
  background = new Sprite();
  tile_set = new TileSet(64, 64, "tileset.png");
  tile_map = new TileMap("tileMap.txt", tile_set);

  //FIXME
  load_assets();

  add_object(new Alien(512, 600, 6));
  add_object(new Alien(800, 540, 6));
  add_object(new Alien(0, 0, 6));
  add_object(new Penguins(704, 640));
  Camera::follow(object_array.back().get());
}

StageState::~StageState(){
  object_array.clear();
  delete tile_map;
  delete tile_set;
  delete background;
}

void StageState::update(float delta){
  InputManager & inputManager = InputManager::get_instance();

  Camera::update(delta);

  if(inputManager.key_press(SDLK_ESCAPE) or inputManager.quit_requested()){
    m_quit_requested = true;
    Game::get_instance().push(new TitleState());
    return;
  }

  // if(inputManager.key_press(SDLK_SPACE)){
  //   int x = inputManager.get_mouse_x() - Camera::pos[LAYER].x;
  //   int y = inputManager.get_mouse_y() - Camera::pos[LAYER].y;
  //   add_object(x, y);
  // }

  update_array(delta);
}

void StageState::load_assets(){
  background->open("res/img/ocean.jpg");
}

void StageState::render(){
  background->render(0, 0);
  tile_map->render(0, 1, Camera::pos);

  render_array();

  tile_map->render(1, 2, Camera::pos);
}

void StageState::pause(){
  //nothing TODO
}

void StageState::resume(){
  //nothing TODO
}

//
// void State::add_object(float mx, float my){
//   float angle = 2 * 3.14159265358979 * (rand()%360) / 360;
//
//   Vector vector(mx + 200, my);
//   vector.rotate(Vector(mx, my), angle);
//
//   object_array.emplace_back(new Face(vector.x, vector.y));
// }
