#ifndef _GAMEOBJECT_H
#include "GameObject.h"
#endif // _GAMEOBJECT_H
#ifndef _PLAYER_H
#define _PLAYER_H
class Player : public GameObject{ // inherit from GameObject
public:
    void load(int x, int y, int width, int height, std::string textureID){
        GameObject::load(x, y, width, height, textureID);
    }

    void draw(SDL_Renderer* p_renderer){
        GameObject::draw(p_renderer);
    }

    void update(){
         go_x -= 1;
    }
    /*
    void update(){
        std::cout << "update player";
        m_x = 10;
        m_y = 20;
    }*/

    void clean(){
        GameObject::clean();
        std::cout << "clean player";
    }
};

#endif
