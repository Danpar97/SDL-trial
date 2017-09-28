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
