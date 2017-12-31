#ifndef TEXTUREMANAGER_H
    #include "TextureManager.h"
#endif // TEXTUREMANAGER_H
#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

class GameObject{
public:
    void load(int x, int y, int width, int height, std::string textureID){
        go_x = x;
        go_y = y;
        go_width = width;
        go_height = height;
        go_textureID = textureID;
        current_row = 1;
        current_frame = 1;
    }
    void draw(SDL_Renderer* p_renderer){
        std::cout << "draw game object";
        TextureManager::getInstance()->drawFrame(go_textureID, go_x, go_y, go_width, go_height, current_row, current_frame, p_renderer);
    }
    void update() {
        go_x += 1;
        std::cout << "update game object";
    }
    void clean() { std::cout << "clean game object"; }
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
