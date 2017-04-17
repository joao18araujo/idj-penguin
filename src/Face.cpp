#include "Face.h"

#include "InputManager.h"
#include "Camera.h"

#define LAYER 0

Face::Face(float x, float y) : sprite(Sprite("penguinface.png")){
  hitpoints = 30;
  box = Rectangle(x, y, sprite.get_width(), sprite.get_height());
}

Face::~Face(){

}

void Face::update(float delta){
  InputManager inputManager = InputManager::get_instance();



  if(inputManager.mouse_press(InputManager::LEFT_MOUSE_BUTTON)) {
      int x = inputManager.get_mouse_x() - Camera::pos[LAYER].x;
      int y = inputManager.get_mouse_y() - Camera::pos[LAYER].y;
      if(this->box.is_inside(x, y)) {
        this->take_damage(rand() % 10 + 10);
      }
  }
}

void Face::render(){
  int x = box.get_draw_x()  + Camera::pos[LAYER].x;
  int y = box.get_draw_y() + Camera::pos[LAYER].y;
  sprite.render(x, y);
}

bool Face::is_dead(){
  return hitpoints <= 0;
}

void Face::take_damage(int damage){
  hitpoints -= damage;
}
