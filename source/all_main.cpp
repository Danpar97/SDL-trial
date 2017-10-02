#include <SDL2/SDL.h>
#include <iostream>

//compile from terminal: g++ -o all_main ./all_main.cpp $(pkg-config --cflags --libs sdl2)

int main(){
    if((SDL_INIT_EVERYTHING) < 0){//failed to initialize
	std::cout << "SDL Failed to initialise.\nSDL Error code: " << SDL_GetError() << std::endl;
        return(-1);
    }
    SDL_Window *w = 0;
    SDL_Renderer *r = 0;
    w = SDL_CreateWindow("Window Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

    if(w == 0){
	std::cout << "SDL failed to create a new window.\nSDL Error code: " << SDL_GetError() << std::endl;
	return(-2);
    }
    r = SDL_CreateRenderer(w, -1, 0);

    //color palette is RGBA sequentially
    SDL_SetRenderDrawColor(r, 128, 128, 0, 255);
    SDL_RenderClear(r);
    SDL_RenderPresent(r);

    //delay before closing in milliseconds
    SDL_Delay(5000);

    //cleanup
    SDL_DestroyWindow(w);
    SDL_Quit();
    return(0);
}
