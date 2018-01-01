#ifndef __GAMEOBJECT_H
#include "GameObject.h"
#endif // _GAMEOBJECT_H
#ifndef __PLAYER_H
#define __PLAYER_H

class Player : public GameObject{ // inherit from GameObject
public:
    void load(int x, int y, int width, int height, std::string textureID){
        GameObject::load(x, y, width, height, textureID);
    }

    void draw(SDL_Renderer* p_renderer){
        std::cout << "draw player" << std::endl;
        GameObject::draw(p_renderer);
    }

    void update(){
        std::cout << "update player" << std::endl;
        go_x -= 1;
        //current_frame = int(((SDL_GetTicks() / 100) % 6));
    }
    /*
    void update(){
        std::cout << "update player";
        m_x = 10;
        m_y = 20;
    }*/

    void clean(){
        std::cout << "clean player" << std::endl;
        GameObject::clean();
    }
};

#endif
