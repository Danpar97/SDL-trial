#include <SDL2/SDL.h>
#include <iostream>

//compile from terminal: g++ -o functional ./functional.cpp $(pkg-config --cflags --libs sdl2)

SDL_Window *w = 0;
SDL_Renderer *r = 0;

bool init_win(const char *tit, int x, int y, int ht, int wt, int flag){
    if((SDL_INIT_EVERYTHING) < 0){//failed to initialize
        std::cout << "SDL Failed to initialise.\nSDL Error code: " << SDL_GetError() << std::endl;
	return(false);
    }
    w = SDL_CreateWindow(tit, x, y, wt, ht, flag);
    if(w == 0){//failed to create a new window
	std::cout << "SDL failed to create a new window.\nSDL Error code: " << SDL_GetError() << std::endl;
	return(false);
    }
    //
    r = SDL_CreateRenderer(w, -1, 0);
    return(true);
}

void render_anim(int8_t col = 0){
    //color palette is RGBA
    SDL_SetRenderDrawColor(r, 0 + col, 0 + (col%2), 0 + (col%3), 255);
    SDL_RenderClear(r);
    SDL_RenderPresent(r);
}

int main(){
   if(!(init_win("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 720, SDL_WINDOW_SHOWN))){
	return(-1);
   }

   int8_t count = 0;
   while(count < 256){
	render_anim(count++);
        SDL_Delay(500);
   }

   //Cleanup
   SDL_DestroyWindow(w);
   SDL_Quit();
   return(0);
}

