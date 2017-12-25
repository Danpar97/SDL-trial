#include "include/sgame.h"
#include <SDL2/SDL_image.h>

//compile from terminal (outdated): g++ -o experimental ./experimental.cpp $(pkg-config --cflags --libs sdl2)
// g++  -I/usr/include/SDL2 -c /home/danish/Repositories/SDL-trial/source/experimental.cpp -o /home/danish/Repositories/SDL-trial/source/experimental.o
//g++  -o /home/danish/Repositories/SDL-trial/source/experimental /home/danish/Repositories/SDL-trial/source/experimental.o  -lSDL2 -lSDL2main -lSDL2_image
skeletal_game::skeletal_game(){
    run = false;
    gwin = NULL;
    gren = NULL;
}

bool skeletal_game::init(const char *title, int x, int y, int ht, int wt, int flag){
    if((SDL_INIT_EVERYTHING) < 0){//failed to initialize
        std::cout << "SDL Failed to initialize!\nSDL Error code: " << SDL_GetError() << std::endl;
        return(false);
    }

    std::cout << "SDL successfully initialized!" << std::endl;
    gwin = SDL_CreateWindow(title, x, y, wt, ht, flag);

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
    texture_manager.load("assets/platform/char9a.png", "animate", gren);

    SDL_Surface *gsurface = IMG_Load("media/platform/char9a.png");
    //SDL_Surface *tmp = SDL_LoadBMP("media/char3(bmp3).bmp");
    gtex = SDL_CreateTextureFromSurface(gren, gsurface);
    SDL_FreeSurface(gsurface);
    SDL_QueryTexture(gtex, NULL, NULL, &src.w, &src.h);
    src.w = 128;
    src.h = 182;
    src.x = 0;
    src.y = 0;
    dest.x = 0;
    dest.y = 0;
    dest.w = src.w;
    dest.h = src.h;

    SDL_SetRenderDrawColor(gren, 255, 0, 0, 255);
    run = true;
    return(true);
}

void skeletal_game::update()
{
    //src.x = 128 * int(((SDL_GetTicks() / 100) % 6));
    current_frame = int(((SDL_GetTicks() / 100) % 6));
}

void skeletal_game::render(){
    SDL_RenderClear(gren);
    texture_manager.draw("animate", 0,0, 128, 82, gren);
    texture_manager.drawFrame("animate", 100,100, 128, 82, 1, current_frame, gren);
    SDL_RenderPresent(gren);
}

void skeletal_game::handleEvents(){
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

void skeletal_game::clean(){
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

int main(){
    skeletal_game obj;
    obj.init("Chapter-02", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 1024, SDL_WINDOW_SHOWN);
    while(obj.getrun()){
        obj.handleEvents();
        obj.update();
        obj.render();
    }
    obj.clean();
    std::cout << "Sanity: Sane" << std::endl;
    return(0);
}
