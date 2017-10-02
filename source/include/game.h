#ifndef  _GLIBCXX_IOSTREAM
    #include <iostream>
#endif // check iostream & include
#ifndef  _SDL_h
    #include <SDL2/SDL.h>
#endif // check SDL & include
#ifndef _game_h
    #define _game_h 1
#endif // _game_h

//compile from terminal: g++ -o test ./test.cpp $(pkg-config --cflags --libs sdl2)

class game{
    bool run;
    SDL_Window *gwin;
    SDL_Renderer *gren;
public:
    game(){
        run = false;
        gwin = NULL;
        gren = NULL;
    }

    ~game(){

    }

    bool getrun(){
        return(run);
    }

    bool init(const char *tit, int x, int y, int ht, int wt, int flag){
        if((SDL_INIT_EVERYTHING) < 0){//failed to initialize
            std::cout << "SDL Failed to initialize!\nSDL Error code: " << SDL_GetError() << std::endl;
            return(false);
        }

        std::cout << "SDL successfully initialized!" << std::endl;
        gwin = SDL_CreateWindow(tit, x, y, wt, ht, flag);

        if(gwin == NULL){//failed to create a new window
            std::cout << "SDL Window initialization failed!\nSDL Error code: " << SDL_GetError() << std::endl;
            return(false);
        }

        std::cout << "SDL successfully created a new window!" << std::endl;
        //create render
        gren = SDL_CreateRenderer(gwin, -1, 0);

        if(gren == NULL){ // renderer init failed
            std::cout << "SDL Renderer initialization failed!\nSDL Error code: " << SDL_GetError() << std::endl;
            return(false);
        }

        std::cout << "Everything initialized successfully!" << std::endl;
        SDL_SetRenderDrawColor(gren, 128, 128, 128, 255);
        run = true;
        return(true);
    }

    void render(){
        SDL_RenderClear(gren); // clear the renderer to the draw color
        SDL_RenderPresent(gren); // draw to the screen
    }

    void handle_event(){
        SDL_Event gevent;
        if(SDL_PollEvent(&gevent)){
            switch (gevent.type){
                case SDL_QUIT:{
                    run = false;
                    break;
                }
                default: break;
            }
        }
    }

    void update(){
        //add body
    }

    void close(){
        std::cout << "Starting cleanup job: " << std::endl;
        SDL_DestroyRenderer(gren);
        std::cout << "SDL Renderer Destroyed!" << std::endl;
        gren = NULL;
        SDL_DestroyWindow(gwin);
        std::cout << "SDL Window Destroyed!" << std::endl;
        gwin = NULL;
        SDL_Quit();
        std::cout << "SDL Deinitialized!\nSDL Quit!" << std::endl;
    }
};
