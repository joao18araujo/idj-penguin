#include "TitleState.h"

#include "InputManager.h"

TitleState::TitleState(){
  background = Sprite("title.jpg");
}

void TitleState::update(float){
  InputManager inputManager = InputManager::get_instance();

  if(inputManager.key_press(SDLK_ESCAPE) or inputManager.quit_requested()){
    m_quit_requested = true;
    return;
  }
}

void TitleState::render(){
  background.render(0, 0);
}

void TitleState::pause(){

}

void TitleState::resume(){

}
