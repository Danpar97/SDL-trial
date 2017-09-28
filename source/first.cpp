#include <SDL2/SDL.h>

//compile from terminal: g++ ./main.cpp $(pkg-config --cflags --libs sdl2)
/*
SDL_Window *vw = 0;
SDL_Renderer *pr = 0;

bool init_win(char *tit, int x, int y, int h, int w, int flag){
    if((SDL_INIT_EVERYTHING) < 0){//failed to initialize
        return(false);
    }
    vw = SDL_CreateWindow(tit, x, y, w, h, flag);
    if(vw != 0){
        pr = SDL_CreateRenderer(vw, -1, 0);
    }
    return(true);
}

void render_anim(){
    //color palette is RGBA
    SDL_SetRenderDrawColor(pr, 128, 128, 0, 255);
    SDL_RenderClear(pr);
    SDL_RenderPresent(pr);
}
*/
int main(){
    if((SDL_INIT_EVERYTHING) < 0){//failed to initialize
        return(-1);
    }
    SDL_Window *vw = 0;
    SDL_Renderer *pr = 0;
    vw = SDL_CreateWindow("Window Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

    if(vw != 0){
        pr = SDL_CreateRenderer(vw, -1, 0);
    }

    //color palette is RGBA sequentially
    SDL_SetRenderDrawColor(pr, 128, 128, 0, 255);
    SDL_RenderClear(pr);
    SDL_RenderPresent(pr);

    //delay before closing in milliseconds
    SDL_Delay(5000);

    //cleanup
    SDL_DestroyWindow(vw);
    SDL_Quit();
    return(0);
}
