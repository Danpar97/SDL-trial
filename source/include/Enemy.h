#ifndef __GAMEOBJECT_H
#include "GameObject.h"
#endif // _GAMEOBJECT_H
#ifndef __ENEMY_H
#define __ENEMY_H

class Enemy : public GameObject{ // inherit from GameObject
public:
    void load(int x, int y, int width, int height, std::string textureID){
        GameObject::load(x, y, width, height, textureID);
    }

    void draw(SDL_Renderer* p_renderer){
        std::cout << "draw enemy" <<std::endl;
        GameObject::draw(p_renderer);
    }

    void update(){
        std::cout << "update enemy" << std::endl;
        go_y += 1;
        go_x += 1;
        current_frame = int(((SDL_GetTicks() / 100) % 6));
    }

    void clean(){
        std::cout << "clean enemy" << std::endl;
        GameObject::clean();
    }
};

#endif
