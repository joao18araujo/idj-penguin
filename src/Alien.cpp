#include "Alien.h"

#include "InputManager.h"
#include "Camera.h"

#include <cmath>
#include <ctime>
#include <cstdlib>

#define SHOOT Alien::Action::ActionType::SHOOT
#define MOVE Action::ActionType::MOVE
#define EPS 8
#define PI 3.14159265358979
#define ANGLE_OFFSET PI/8
#define ANGULAR_SPEED PI/128

Alien::Alien(float x, float y, int m_minions){
  sprite = Sprite("alien.png");
  hp = 30;
  speed = Vector(1, 1);
  box = Rectangle(x, y, sprite.get_width(), sprite.get_height());

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

}

void Alien::update(float delta){
  rotation = fmod(rotation + ANGULAR_SPEED * delta, 2 * PI);

  InputManager inputManager = InputManager::get_instance();

  bool left_click = inputManager.mouse_press(InputManager::LEFT_MOUSE_BUTTON);
  bool right_click = inputManager.mouse_press(InputManager::RIGHT_MOUSE_BUTTON);

  if(left_click or right_click) {
    int x = inputManager.get_mouse_x() - Camera::pos[LAYER].x;
    int y = inputManager.get_mouse_y() - Camera::pos[LAYER].y;

    Action::ActionType type = left_click ? SHOOT : MOVE;
    task_queue.emplace(type, x, y);
  }

  if(not task_queue.empty()){
    Action action = task_queue.front();
    if(action.type == SHOOT){
      float min_distance = 1e9;
      Minion minion;

      for(auto & m : minion_array){
        float distance = m.distance(action.pos);
        if(distance < min_distance){
          minion = m;
          min_distance = distance;
        }
      }

      minion.shoot(action.pos);

      task_queue.pop();
    }
    else if(action.type == MOVE){
      if(arrived(action.pos)){
        task_queue.pop();
        box.set_x(action.pos.x);
        box.set_y(action.pos.y);
      }else{
        double angle = atan2(action.pos.y - box.get_y(), action.pos.x - box.get_x());

        speed.x = cos(angle) * 4;
        speed.y = sin(angle) * 4;

        box.set_x(box.get_x() + speed.x * delta);
        box.set_y(box.get_y() + speed.y * delta);
      }
    }
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
