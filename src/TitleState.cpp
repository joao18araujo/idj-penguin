#include "TitleState.h"

#include "InputManager.h"
#include "Game.h"
#include "StageState.h"

TitleState::TitleState(){
  text = new Text("Call me maybe.ttf", 45, Text::TextStyle::BLENDED, "PRESS SPACE TO PLAY",
       {0, 48, 255, 255}, 250, 500);
  background = Sprite("title.jpg");
}

void TitleState::update(float delta){
  InputManager inputManager = InputManager::get_instance();

  timer.update(delta);
  if(inputManager.key_press(SDLK_ESCAPE) or inputManager.quit_requested()){
    m_quit_requested = true;
    return;
  }

  if(inputManager.key_press(SDLK_SPACE)){
    m_quit_requested = true;
    Game::get_instance().push(new StageState());
    return;
  }
}

void TitleState::render(){
  background.render(0, 0);
  printf("Tempo: %f\n", timer.get());
  if(timer.get() < 125){
    text->render(250, 500);
  }
  if(timer.get() > 200){
    timer.restart();
  }
}

void TitleState::pause(){

}

void TitleState::resume(){

}
