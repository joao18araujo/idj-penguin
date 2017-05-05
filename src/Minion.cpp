#include "Minion.h"

#define LAYER 0

#include "Camera.h"
#include "Bullet.h"
#include "Game.h"

#define PI 3.14159265358979
#define ANGULAR_SPEED -PI/128

Minion::Minion(GameObject * minion_center, float arc_offset, float scale){
  center = minion_center;
  sprite = Sprite("minion.png");

  arc = arc_offset;

  sprite.set_scale_x(scale);
  sprite.set_scale_y(scale);

  float x = center->box.get_x() + 200 * cos(arc);
  float y = center->box.get_y() + 200 * sin(arc);
  printf("Center = %f, %f\n", center->box.get_x(), center->box.get_y());
  box = Rectangle(x, y, sprite.get_width(), sprite.get_height());
}

void Minion::update(float delta){
  arc = fmod(arc + ANGULAR_SPEED * delta, 2 * PI);
  rotation = fmod(arc + PI/2, 2 * PI);
  box.set_x(center->box.get_x() + 200 * cos(arc));
  box.set_y(center->box.get_y() + 200 * sin(arc));
}

void Minion::render(){
  int x = box.get_draw_x()  + Camera::pos[LAYER].x;
  int y = box.get_draw_y() + Camera::pos[LAYER].y;
  sprite.render(x, y, rotation);
}

bool Minion::is_dead(){
  return false;
}

void Minion::shoot(Vector pos){
  float angle  = atan2(pos.y - box.get_y(), pos.x - box.get_x());
  Bullet * bullet = new Bullet(box.get_x(), box.get_y(), angle, 20, 500, "minionbullet1.png");
  bullet->rotation = angle;

  Game::get_instance().get_state().add_object(bullet);
}
