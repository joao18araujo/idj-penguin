#include "Game.h"

#include "StageState.h"

int main(int, char **){
  Game game("Joao Vitor Araujo 14/0023518", 1024, 600);
  State * state =  new StageState();
  game.push(state);
  game.run();

  return 0;
}
