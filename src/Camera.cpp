#include "Camera.h"
#include "InputManager.h"

GameObject * Camera::focus = nullptr;
Vector Camera::speed;
Vector Camera::pos[LAYERS];
float Camera::layer_speed[LAYERS] = {4, 6, 16, 32};

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

    for(int i = 0; i < LAYERS; ++i){
      pos[i].x += speed.x * layer_speed[i];
      pos[i].y += speed.y * layer_speed[i];
    }
  }else{
    //TODO proximo tX
  }
}
