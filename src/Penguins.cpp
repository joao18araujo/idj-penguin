#include "Penguins.h"

#include "InputManager.h"
#include "Camera.h"
#include "Bullet.h"
#include "Game.h"

#include <algorithm>
#include <cmath>

Penguins * Penguins::player = nullptr;

#define ACCELERATION 0.1
#define PI 3.14159265358979
#define ANGULAR_SPEED PI/128
#define SPEED_LIMIT 5.0
#define LAYER 0

using std::max;
using std::min;

Penguins::Penguins(float x, float y){
  body_sprite = Sprite("penguin.png");
  cannon_sprite = Sprite("cubngun.png");
  speed = Vector(1, 1);
  linear_speed = 0;
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
  InputManager inputManager = InputManager::get_instance();

  if(inputManager.is_key_down(SDLK_w)){
    linear_speed = min(linear_speed + ACCELERATION * delta, SPEED_LIMIT);
  }
  if(inputManager.is_key_down(SDLK_s)){
    linear_speed = max(linear_speed - ACCELERATION * delta, -SPEED_LIMIT);
  }
  if(inputManager.is_key_down(SDLK_a)){
    rotation = fmod(2*PI + rotation - ANGULAR_SPEED * delta, 2 * PI);
  }
  if(inputManager.is_key_down(SDLK_d)){
    rotation = fmod(rotation + ANGULAR_SPEED * delta, 2 * PI);
  }
  if(inputManager.mouse_press(InputManager::LEFT_MOUSE_BUTTON)){
    shoot();
  }

  int x = inputManager.get_mouse_x() - Camera::pos[LAYER].x;
  int y = inputManager.get_mouse_y() - Camera::pos[LAYER].y;
  float delta_x = x - box.get_x();
  float delta_y = y - box.get_y();
  cannon_angle = delta_x ? atan2(delta_y, delta_x) : 0;

  speed.transform(linear_speed, rotation);
  box.set_x(box.get_x() + speed.x * delta);
  box.set_y(box.get_y() + speed.y * delta);
}

void Penguins::render(){
  int x = box.get_draw_x()  + Camera::pos[LAYER].x;
  int y = box.get_draw_y() + Camera::pos[LAYER].y;
  int cannon_x = box.get_x() - cannon_sprite.get_width()/2 + Camera::pos[LAYER].x;
  int cannon_y = box.get_y() - cannon_sprite.get_height()/2 + Camera::pos[LAYER].y;
  body_sprite.render(x, y, rotation);
  cannon_sprite.render(cannon_x, cannon_y, cannon_angle);
}

bool Penguins::is_dead(){
 return hp <= 0;
}

void Penguins::shoot(){
  Vector v;
  v.transform(box.get_width() * 0.5, cannon_angle);
  Bullet * bullet = new Bullet(box.get_x() + v.x, box.get_y() + v.y, cannon_angle, 5, 500, 4, 6,"penguinbullet.png");
  bullet->rotation = cannon_angle;

  Game::get_instance().get_state().add_object(bullet);
}
