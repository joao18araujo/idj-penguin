#include "Bullet.h"

#include "Camera.h"

#include <string>
#include <cmath>

#define LAYER 0

Bullet::Bullet(float x, float y, float angle, float m_speed, float max_distance, string sp){
  sprite = Sprite(sp);
  box = Rectangle(x, y, sprite.get_width(), sprite.get_height());

  modular_speed = m_speed;
  speed.x = modular_speed * cos(angle);
  speed.y = modular_speed * sin(angle);

  distance_left = max_distance;
}

void Bullet::update(float delta){
  box.set_x(box.get_x() + speed.x * delta);
  box.set_y(box.get_y() + speed.y * delta);
  distance_left -= modular_speed;
}

void Bullet::render(){
  int x = box.get_draw_x()  + Camera::pos[LAYER].x;
  int y = box.get_draw_y() + Camera::pos[LAYER].y;
  sprite.render(x, y, rotation);
}

bool Bullet::is_dead(){
  return distance_left <= 0;
}
