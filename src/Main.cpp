#include "Game.h"

#include "TitleState.h"

int main(int, char **){
  Game game("Joao Vitor Araujo 14/0023518", 1024, 600);
  State * state =  new TitleState();
  game.push(state);
  game.run();

  return 0;
}
