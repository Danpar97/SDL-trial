#ifndef  _GLIBCXX_IOSTREAM
    #include <iostream>
#endif // check iostream & include
#ifndef  _SDL_h
    #include <SDL2/SDL.h>
#endif // check SDL & include
#ifndef _game_h
    #define _game_h 1
#endif // _game_h

//compile from terminal: g++ ./test.cpp $(pkg-config --cflags --libs sdl2)

class gstate{
    SDL_Window *gwindow = NULL;
    SDL_Surface *gsurface = NULL;
    SDL_Surface *gimg = NULL;
    SDL_Renderer *grender = NULL;
public:
    bool init(const char *tit, int x, int y, int ht, int wt, int flag){
        if((SDL_INIT_EVERYTHING) < 0){//failed to initialize
            std::cout << "SDL Failed to initialise!\nSDL Error code: " << SDL_GetError() << std::endl;
            return(false);
        }
        gwindow = SDL_CreateWindow(tit, x, y, wt, ht, flag);
        if(gwindow == 0){//failed to create a new window
            std::cout << "SDL failed to create a new window!\nSDL Error code: " << SDL_GetError() << std::endl;
            return(false);
        }
        //get window surface
        gsurface = SDL_GetWindowSurface(gwindow);
        grender = SDL_CreateRenderer(gwindow, -1, 0);
        return(true);
    }
    bool load_media(const char *path) {
        //Load BMP image
        gimg = SDL_LoadBMP(path);
        if(gimg == 0) { //failed to load media
            std::cout << "Unable to load image " << path << "!\nSDL Error: " << SDL_GetError() << std::endl;
            return(false);
        }
        return(true);
    }
    void render(){
        //color palette is RGBA
        //A = alpha,transparency/opacity
        SDL_SetRenderDrawColor(grender, 0, 0, 0, 128);
        SDL_RenderClear(grender);
        SDL_RenderPresent(grender);
    }
    void update(){

    }
    void handle_event(){

    }
    void cleanup(){
        SDL_DestroyWindow(gwindow);
        SDL_Quit();
    }
};

