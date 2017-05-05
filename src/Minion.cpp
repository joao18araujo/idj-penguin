#include "Minion.h"

#define LAYER 0

#include "Camera.h"

#define PI 3.14159265358979
#define ANGULAR_SPEED PI/16

Minion::Minion(GameObject * minion_center, float arc_offset){
  center = minion_center;
  sprite = Sprite("minion.png");

  arc = arc_offset;

  float x = center->box.get_x() + 200 * cos(arc);
  float y = center->box.get_y() + 200 * sin(arc);
  box = Rectangle(x, y, sprite.get_width(), sprite.get_height());
}

void Minion::update(float delta){
  arc = fmod(arc + ANGULAR_SPEED * delta, 2 * PI);
  printf("arc = %f\n", arc);
  box.set_x(center->box.get_x() + 200 * cos(arc));
  box.set_y(center->box.get_y() + 200 * sin(arc));
}

void Minion::render(){
  int x = box.get_draw_x()  + Camera::pos[LAYER].x;
  int y = box.get_draw_y() + Camera::pos[LAYER].y;
  sprite.render(x, y);
}

bool Minion::is_dead(){
  return false;
}

void Minion::shoot(Vector pos){

}
