#include "include/sgame.h"

//compile from terminal: g++ -o experimental ./experimental.cpp $(pkg-config --cflags --libs sdl2)

skeletal_game::skeletal_game(){
    run = false;
    gwin = NULL;
    gren = NULL;
}

bool skeletal_game::init(const char *tit, int x, int y, int ht, int wt, int flag){
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
    SDL_Surface* tmp = SDL_LoadBMP("media/char3(24).bmp");
    gtex = SDL_CreateTextureFromSurface(gren, tmp);
    SDL_FreeSurface(tmp);
    //SDL_QueryTexture(gtex, NULL, NULL, &src.w, &src.h);
    src.w = 128;
    src.h = 82;
    src.x = 0;
    src.y = 0;
    dest.x = 0;
    dest.y = 0;
    dest.w = src.w;
    dest.h = src.h;

    SDL_SetRenderDrawColor(gren, 0, 0, 0, 255);
    run = true;
    return(true);
}

void skeletal_game::update()
{
    src.x = 128 * int(((SDL_GetTicks() / 100) % 3));
}

void skeletal_game::render(){
    SDL_RenderClear(gren); // clear the renderer to the draw color
    SDL_RenderCopy(gren, gtex, &src, &dest);// display image
    SDL_RenderPresent(gren); // draw to the screen
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
