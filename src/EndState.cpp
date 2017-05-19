#include "EndState.h"

#include "InputManager.h"
#include "Game.h"
#include "StageState.h"
#include "TitleState.h"

EndState::EndState(StateData state_data){
  if(state_data.player_victory){
    background = Sprite("win.jpg");
    music = Music("endStateWin.ogg");
  }else{
    background = Sprite("lose.jpg");
    music = Music("endStateLose.ogg");
  }

  instruction = new Text("Call me maybe.ttf", 40, Text::TextStyle::SOLID, "PRESS SPACE TO PLAY",
       {0, 48, 255, 255}, 300, 500);

  //instruction = new Text("Call me maybe.ttf", 45, Text::TextStyle::BLENDED, "PRESS ESC TO GO TO MENU OR SPACE TO PLAY", {0, 48, 255, 255}, 0, 0);

}

void EndState::update(float delta){
  InputManager inputManager = InputManager::get_instance();

  //timer.update(delta);
  if(inputManager.key_press(SDLK_ESCAPE)){
    m_quit_requested = true;
    Game::get_instance().push(new TitleState());
    return;
  }

  if(inputManager.key_press(SDLK_SPACE)){
    m_quit_requested = true;
    Game::get_instance().push(new StageState());
    return;
  }

  timer.update(delta);
  if(timer.get() > 200){
    timer.restart();
  }
}

void EndState::render(){
  background.render(0, 0);

  if(timer.get() < 125){
    instruction->render(0, 0);
  }
  instruction->render(0, 0);

}

void EndState::pause(){

}

void EndState::resume(){

}
