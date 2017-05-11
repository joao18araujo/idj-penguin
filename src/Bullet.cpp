#include "Bullet.h"

#include "Camera.h"

#include <string>
#include <cmath>

#define LAYER 0

Bullet::Bullet(float x, float y, float angle, float m_speed, float max_distance,
                float frame_count, float frame_time, string sp){
  sprite = Sprite(sp, frame_count, frame_time);
  box = Rectangle(x, y, sprite.get_width(), sprite.get_height());

  modular_speed = m_speed;
  speed.transform(modular_speed, angle);

  distance_left = max_distance;
}

void Bullet::update(float delta){
  box.set_x(box.get_x() + speed.x * delta);
  box.set_y(box.get_y() + speed.y * delta);
  distance_left -= modular_speed * delta;
  sprite.update(delta);
}

void Bullet::render(){
  int x = box.get_draw_x()  + Camera::pos[LAYER].x;
  int y = box.get_draw_y() + Camera::pos[LAYER].y;
  sprite.render(x, y, rotation);
}

bool Bullet::is_dead(){
  return distance_left <= 0;
}

void Bullet::notify_collision(GameObject & object){
  if(not object.is("bullet")){
    distance_left = 0;
  }
}

bool Bullet::is(string type){
  return type == "bullet";
}
