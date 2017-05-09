#include "Penguins.h"

Penguins * Penguins::player = nullptr;

Penguins::Penguins(float x, float y){
  body_sprite = Sprite("penguin.png");
  cannon_sprite = Sprite("cubngun.png");
  speed = Vector(1, 1);
  linear_speed = 1;
  cannon_angle = 0;
  hp = 100;
  rotation = 0;
  box = Rectangle(x, y, body_sprite.get_width(), body_sprite.get_height());
  player = this;
}

Penguins::~Penguins(){
  player = nullptr;
}

void Penguins::update(float delta){

}

void Penguins::render(){

}

bool Penguins::is_dead(){
 return hp <= 0;
}

void Penguins::shoot(){

}
