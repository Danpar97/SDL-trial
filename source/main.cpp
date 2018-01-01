#include "include/sgame.h"
#include <SDL2/SDL_image.h>

// g++ -I/usr/include/SDL2 -c /home/danish/Repositories/SDL-trial/source/experimental.cpp -o /home/danish/Repositories/SDL-trial/source/experimental.o
// g++ -o /home/danish/Repositories/SDL-trial/source/experimental /home/danish/Repositories/SDL-trial/source/experimental.o  -lSDL2 -lSDL2main -lSDL2_image
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
    //texture_manager.load("media/platform/char9b.png", "animate", gren);

    if(!TextureManager::getInstance()->load("media/platform/char9b.png", "Lion", gren)){
        return(false);
    }

    if(!TextureManager::getInstance()->load("media/platform/char10b.png", "Dragon", gren)){
        return(false);
    }

    if(!TextureManager::getInstance()->load("media/platform/char3a.png", "Elephant", gren)){
        return(false);
    }

    g_go = new GameObject();
    g_player = new Player();
    g_enemy = new Enemy();

    g_go->load(100, 100, 128, 82, "Lion");
    g_player->load(300, 300, 128, 82, "Dragon");
    g_enemy->load(0, 0, 136, 82, "Elephant");

    g_game_objects.push_back(g_go);
    g_game_objects.push_back(g_player);
    g_game_objects.push_back(g_enemy);

    SDL_SetRenderDrawColor(gren, 255, 0, 0, 255);
    run = true;
    return(true);
}

void skeletal_game::draw(){
    for(std::vector<GameObject*>::size_type i = 0; i != g_game_objects.size(); ++i){
        g_game_objects[i]->draw(gren);
    }
}

void skeletal_game::update(){
    // loop through and update our objects
    for(std::vector<GameObject*>::size_type i = 0; i != g_game_objects.size(); ++i){
        g_game_objects[i]->update();
    }
}

void skeletal_game::render(){
    SDL_RenderClear(gren);

    // loop through our objects and draw them
    for(std::vector<GameObject*>::size_type i = 0; i != g_game_objects.size(); ++i){
        g_game_objects[i]->draw(gren);
    }

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
    obj.init("Chapter-03", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 1024, SDL_WINDOW_SHOWN);
    while(obj.getrun()){
        obj.handleEvents();
        obj.update();
        obj.render();
        SDL_Delay(10); // add the delay
    }
    obj.clean();
    std::cout << "Sanity: Sane" << std::endl;
    return(0);
}
