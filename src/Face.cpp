#include "Face.h"

#include "InputManager.h"

Face::Face(float x, float y) : sprite(Sprite("penguinface.png")){
  hitpoints = 30;
  box = Rectangle(x, y, sprite.get_width(), sprite.get_height());
}

Face::~Face(){

}

void Face::update(float delta){
  InputManager inputManager = InputManager::get_instance();

  if(inputManager.mouse_press(InputManager::LEFT_MOUSE_BUTTON)) {
      if(this->box.is_inside(inputManager.get_mouse_x(), inputManager.get_mouse_y())) {
        this->take_damage(rand() % 10 + 10);
      }
  }
}

void Face::render(){
  sprite.render(box.get_draw_x(), box.get_draw_y());
}

bool Face::is_dead(){
  return hitpoints <= 0;
}

void Face::take_damage(int damage){
  hitpoints -= damage;
}
