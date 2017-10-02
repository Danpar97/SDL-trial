#include "include/game.h"

//compile from terminal: g++ ./third.cpp $(pkg-config --cflags --libs sdl2)

int main(){
  game obj;
  obj.init("Chapter-01", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
  while(obj.getrun()){
    obj.handle_event();
    //obj.update();
    obj.render();
  }
  obj.close();
  std::cout << "Sanity: Sane" << std::endl;
  return(0);
}
