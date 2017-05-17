#include "Alien.h"

#include "InputManager.h"
#include "Camera.h"
#include "Bullet.h"
#include "Animation.h"
#include "Game.h"
#include "Penguins.h"
#include "Sound.h"

#include <cmath>
#include <ctime>
#include <cstdlib>

#define SHOOT Alien::Action::ActionType::SHOOT
#define MOVE Action::ActionType::MOVE
#define RESTING AlienState::RESTING
#define MOVING AlienState::MOVING
#define EPS 8
#define PI 3.14159265358979
#define ANGLE_OFFSET PI/8
#define ANGULAR_SPEED PI/128

int Alien::alien_count = 0;

Alien::Alien(float x, float y, int m_minions){
  sprite = Sprite("alien.png");
  hp = 100;
  speed = Vector(1, 1);
  box = Rectangle(x, y, sprite.get_width(), sprite.get_height());
  state = RESTING;
  srand(clock());
  cooldown = 50 + rand()%201;

  ++alien_count;
  srand(time(nullptr));

  //preenche minions
  float angle_offset = m_minions ? 2 * PI / m_minions : 0;
  float initial_arc = 0;
  while(m_minions--){
    float scale = (10 + (rand()%5)) / 10.0;
    minion_array.emplace_back(this, initial_arc, scale);
    initial_arc = fmod(initial_arc + angle_offset, 2 * PI);
  }
}

Alien::~Alien(){
  ++alien_count;
}

void Alien::update(float delta){
  rotation = fmod(rotation + ANGULAR_SPEED * delta, 2 * PI);

  switch(state){
    case RESTING:
      if(Penguins::player == nullptr) break;
      if(rest_timer.get() < cooldown){
        rest_timer.update(delta);
      }else{
        state = MOVING;
        rest_timer.restart();
        Rectangle rect = Penguins::player->box;
        destination = Vector(rect.get_x(), rect.get_y());
        double angle = atan2(rect.get_y() - box.get_y(), rect.get_x() - box.get_x());
        speed.transform(4, angle);
      }
      break;

    case MOVING:
      if(Penguins::player == nullptr) break;
      if(arrived(destination)){
        box.set_x(destination.x);
        box.set_y(destination.y);

        shoot();
        state = RESTING;
      }else{
        box.set_x(box.get_x() + speed.x * delta);
        box.set_y(box.get_y() + speed.y * delta);
      }
      break;
      default:
      break;
  }

  for(auto & minion : minion_array){
    minion.update(delta);
  }
}

void Alien::render(){
  int x = box.get_draw_x()  + Camera::pos[LAYER].x;
  int y = box.get_draw_y() + Camera::pos[LAYER].y;
  sprite.render(x, y, rotation);

  for(auto & minion : minion_array){
    minion.render();
  }
}

bool Alien::is_dead(){
  return hp <= 0;
}

bool Alien::arrived(Vector pos){
  float delta_x = fabs(box.get_x() - pos.x);
  float delta_y = fabs(box.get_y() - pos.y);

  return delta_x <= EPS and delta_y <= EPS;
}

void Alien::notify_collision(GameObject & object){
  if(object.is("bullet")){
    Bullet & b = dynamic_cast<Bullet &>(object);
    if(b.target("alien")){
      hp -= 50;
      if(is_dead()){
        Animation * animation = new Animation(box.get_x(), box.get_y(), rotation, "aliendeath.png",
                  4, 10, true);
                  Game::get_instance().get_current_state().add_object(animation);
        Sound * sound = new Sound("boom.wav");
        sound->play(0);
      }
    }
  }
}

bool Alien::is(string type){
  return type == "alien";
}

void Alien::shoot(){
  float min_distance = 1e9;
  Minion minion;

  Rectangle rect = Penguins::player->box;
  Vector v = Vector(rect.get_x(), rect.get_y());

  for(auto & m : minion_array){
    float distance = m.distance(v);
    if(distance < min_distance){
      minion = m;
      min_distance = distance;
    }
  }

  minion.shoot(v);
}
