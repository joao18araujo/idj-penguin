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
#include "StateData.h"
#include "EndState.h"

#include <ctime>

#define LAYER 0

StageState::StageState(){
  background = new Sprite();
  tile_set = new TileSet(64, 64, "tileset.png");
  tile_map = new TileMap("tileMap.txt", tile_set);

  add_object(new Alien(512, 600, 6));
  add_object(new Alien(800, 540, 6));
  add_object(new Alien(0, 0, 6));
  add_object(new Alien(1000, 100, 6));
  add_object(new Alien(300, 0, 6));
  n_aliens = 5;

  add_object(new Penguins(704, 640));

  music = new Music("stageState.ogg");
  music->play(-1);

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

  update_array(delta);

  count_deaths();
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

}

void StageState::resume(){

}

void StageState::count_deaths(){
  bool aliens = false, penguins = false;
  for(auto & object : object_array){
    if(object->is("alien")) aliens = true;
    else if(object->is("penguins")) penguins = true;
  }

  StateData data;
  if(not penguins){
    m_quit_requested = true;
    data.player_victory = false;
    Game::get_instance().push(new EndState(data));
    return;
  }else if(not aliens){
    m_quit_requested = true;
    data.player_victory = true;
    Game::get_instance().push(new EndState(data));
    return;
  }
}
