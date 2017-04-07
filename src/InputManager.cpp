#include "InputManager.h"

#include <cstring>

InputManager::InputManager(){
  memset(mouse_state, 0, sizeof mouse_state);
  memset(mouse_update, 0, sizeof mouse_update);
}

InputManager::~InputManager(){
  key_state.clear();
  key_update.clear();
}

void InputManager::update(){

}

bool InputManager::key_press(int key){

}

bool InputManager::key_release(int key){

}

bool InputManager::is_key_down(int key){

}

bool InputManager::mouse_press(int button){

}

bool InputManager::mouse_release(int button){

}
bool InputManager::is_mouse_down(int button){

}

int InputManager::get_mouse_x(){

}

int InputManager::get_mouse_y(){

}

bool InputManager::quit_requested(){

}

static InputManager & InputManager::get_instance(){
  static InputManager & input_manager;
  return input_manager;
}
