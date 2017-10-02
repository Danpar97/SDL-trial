#include "include/game2.h"

//compile from terminal: g++ -o load_bmp ./load_bmp.cpp $(pkg-config --cflags --libs sdl2)

int main(){
  game obj;
  obj.init("Chapter-02", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 1024, SDL_WINDOW_SHOWN);
  while(obj.getrun()){
    obj.handle_event();
    //obj.update();
    obj.render();
  }
  obj.close();
  std::cout << "Sanity: Sane" << std::endl;
  return(0);
}
