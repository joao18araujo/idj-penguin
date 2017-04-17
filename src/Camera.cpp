#include "Camera.h"
#include "InputManager.h"

GameObject * Camera::focus = nullptr;
Vector Camera::speed;
Vector Camera::pos;

void Camera::follow(GameObject * new_focus){
  focus = new_focus;
}

void Camera::unfollow(){
  focus = nullptr;
}

void Camera::update(float delta){
  InputManager inputManager = InputManager::get_instance();

  if(focus == nullptr){
    bool directions[] = {
      inputManager.is_key_down(InputManager::LEFT_ARROW_KEY),
      inputManager.is_key_down(InputManager::UP_ARROW_KEY),
      inputManager.is_key_down(InputManager::RIGHT_ARROW_KEY),
      inputManager.is_key_down(InputManager::DOWN_ARROW_KEY)
    };

    speed.x = 0;
    speed.y = 0;
    for(int i = 0; i < 4; ++i){
      speed.x += ((i+1) % 2) * (i - 1) * directions[i] * delta;
      speed.y += (i % 2) * (i - 2) * directions[i] * delta;
    }

    pos.x += speed.x;
    pos.y += speed.y;

    printf("(%.2f %.2f)\n", pos.x, pos.y);
  }else{

  }
}
