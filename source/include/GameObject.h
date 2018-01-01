#ifndef __TEXTUREMANAGER_H
    #include "TextureManager.h"
#endif // TEXTUREMANAGER_H
#ifndef __GAMEOBJECT_H
#define __GAMEOBJECT_H

class GameObject{
public:
    virtual void load(int x, int y, int width, int height, std::string textureID){
        go_x = x;
        go_y = y;
        go_width = width;
        go_height = height;
        go_textureID = textureID;
        current_row = 1;
        current_frame = 1;
    }
    virtual void draw(SDL_Renderer* p_renderer){
        std::cout << "draw game object";
        TextureManager::getInstance()->drawFrame(go_textureID, go_x, go_y, go_width, go_height, current_row, current_frame, p_renderer);
    }
    virtual void update() {
        go_x += 1;
        std::cout << "update game object";
    }
    virtual void clean() { std::cout << "clean game object"; }
protected:
    int go_x;
    int go_y;
    std::string go_textureID;
    int current_frame;
    int current_row;
    int go_width;
    int go_height;
};

#endif
