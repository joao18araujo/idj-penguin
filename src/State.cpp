#include "State.h"
#include "Sprite.h"

State::State(){
  background = new Sprite();
}

bool State::quit_requested(){
  return m_quit_requested;
}

void State::load_assets(){
  background->open("res/img/ocean.jpg");
}

void State::update(float delta){
  if(SDL_QuitRequested() == SDL_TRUE){
    m_quit_requested = true;
  }
}

void State::render(){
  background->render(0, 0);
}
