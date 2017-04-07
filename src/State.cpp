#include "State.h"
#include "Face.h"
#include "Sprite.h"
#include "Vector.h"

State::State(){
  background = new Sprite();
  tile_set = new TileSet(64, 64, "tileset.png");
  tile_map = new TileMap("tileMap.txt", tile_set);
}

State::~State(){
  object_array.clear();
  delete tile_map;
  delete tile_set;
  delete background;
}

bool State::quit_requested(){
  return m_quit_requested;
}

void State::load_assets(){
  background->open("res/img/ocean.jpg");
}

void State::update(float delta){
  input();

  for(auto p = object_array.begin(); p < object_array.end(); ++p){
    if((*p)->is_dead()){
      object_array.erase(p);
    }
  }
}

void State::render(){
  background->render(0, 0);
  tile_map->render(0, 0);

  for(auto & go : object_array){
    go->render();
  }
}

void State::input() {

    SDL_Event event;
    int mouseX, mouseY;

    // Obtenha as coordenadas do mouse
    SDL_GetMouseState(&mouseX, &mouseY);

    // SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
    while (SDL_PollEvent(&event)) {

        // Se o evento for quit, setar a flag para terminação
        if(event.type == SDL_QUIT) {
            m_quit_requested = true;
        }

        // Se o evento for clique...
        if(event.type == SDL_MOUSEBUTTONDOWN) {

            // Percorrer de trás pra frente pra sempre clicar no objeto mais de cima
            for(int i = object_array.size() - 1; i >= 0; --i) {
                // Obtem o ponteiro e casta pra Face.
                Face* face = (Face*) object_array[i].get();
                // Nota: Desencapsular o ponteiro é algo que devemos evitar ao máximo.
                // O propósito do unique_ptr é manter apenas uma cópia daquele ponteiro,
                // ao usar get(), violamos esse princípio e estamos menos seguros.
                // Esse código, assim como a classe Face, é provisório. Futuramente, para
                // chamar funções de GameObjects, use objectArray[i]->função() direto.

                if(face->box.is_inside((float)mouseX, (float)mouseY)) {
                    // Aplica dano
                    face->take_damage(rand() % 10 + 10);
                    // Sai do loop (só queremos acertar um)
                    break;
                }
            }
        }
        if( event.type == SDL_KEYDOWN ) {
            // Se a tecla for ESC, setar a flag de quit
            if( event.key.keysym.sym == SDLK_ESCAPE ) {
                m_quit_requested = true;
            }
            // Se não, crie um objeto
            else {
                add_object((float)mouseX, (float)mouseY);
            }
        }
    }
}


void State::add_object(float mx, float my){
  float angle = 2 * 3.14159265358979 * (rand()%360) / 360;

  Vector vector(mx + 200, my);
  vector.rotate(Vector(mx, my), angle);

  object_array.emplace_back(new Face(vector.get_x(), vector.get_y()));
}
