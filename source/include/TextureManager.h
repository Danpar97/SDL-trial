#ifndef _GLIBCXX_MAP
    #include <map>
#endif // _GLIBCXX_MAP
#ifndef _SDL_IMAGE_H
    #include <SDL2/SDL_image.h>
#endif // _SDL_IMAGE_H
#ifndef TEXTUREMANAGER_H_INCLUDED
#define TEXTUREMANAGER_H_INCLUDED

class TextureManager{
    private:
        std::map<std::string, SDL_Texture*> texture_map;
    public:
        bool load(std::string fileName, std::string id, SDL_Renderer* render);
        // draw
        void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* render, SDL_RendererFlip flip = SDL_FLIP_NONE);
        // drawframe
        void drawFrame(std::string id, int x, int y, int width, int height, int current_row, int current_frame, SDL_Renderer* render, SDL_RendererFlip flip = SDL_FLIP_NONE);
        //TextureManager();
        //~TextureManager();
};

/*

-----------------------------------------------------------Definitions------------------------------------------------------------------

*/

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer* render) {
    SDL_Surface* temp_surface = IMG_Load(fileName.c_str());
    if(temp_surface == 0) {
        return false;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(render, temp_surface);
    SDL_FreeSurface(temp_surface);

    // everything went ok, add the texture to our list
    if(texture != 0) {
        texture_map[id] = texture;
        return true;
    }

    // reaching here means something went wrong
    return false;
}

void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer* render, SDL_RendererFlip flip) {
    SDL_Rect src_rect;
    SDL_Rect dest_rect;
    src_rect.x = 0;
    src_rect.y = 0;
    src_rect.w = dest_rect.w = width;
    src_rect.h = dest_rect.h = height;
    dest_rect.x = x;
    dest_rect.y = y;
    SDL_RenderCopyEx(render, texture_map[id], &src_rect, &dest_rect, 0, 0, flip);
}

void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int current_row, int current_frame, SDL_Renderer* render, SDL_RendererFlip flip) {
    SDL_Rect src_rect;
    SDL_Rect dest_rect;
    src_rect.x = width * current_frame;
    src_rect.y = height * (current_row - 1);
    src_rect.w = dest_rect.w = width;
    src_rect.h = dest_rect.h = height;
    dest_rect.x = x;
    dest_rect.y = y;
    SDL_RenderCopyEx(render, texture_map[id], &src_rect, &dest_rect, 0, 0, flip);
}

#endif // TEXTUREMANAGER_H_INCLUDED
