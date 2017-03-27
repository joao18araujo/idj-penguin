#include "Face.h"

Face::Face(float x, float y) : sprite(Sprite("penguinface.png")){
  box = Rectangle(x, y, sprite.get_width(), sprite.get_height());
}

Face::~Face(){

}

void Face::update(float delta){

}

void Face::render(){

}

bool Face::is_dead(){
  return true;
}

void Face::take_damage(int damage){

}
