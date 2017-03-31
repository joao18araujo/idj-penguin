#include "Face.h"

Face::Face(float x, float y) : sprite(Sprite("penguinface.png")){
  box = Rectangle(x, y, sprite.get_width(), sprite.get_height());
}

Face::~Face(){

}

void Face::update(float delta){

}

void Face::render(){
  sprite.render(box.get_draw_x(), box.get_draw_y());
}

bool Face::is_dead(){
  return false;
}

void Face::take_damage(int damage){

}
