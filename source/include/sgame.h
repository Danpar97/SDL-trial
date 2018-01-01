#ifndef  _GLIBCXX_IOSTREAM
    #include <iostream>
#endif // check iostream & include
#ifndef _VECTOR_TCC
    #include <vector>
#endif // _VECTOR_TCC
#ifndef  _SDL_h
    #include <SDL2/SDL.h>
#endif // check SDL & include
#ifndef _SDL_IMAGE_H
    #include <SDL2/SDL_image.h>
#endif // _SDL_IMAGE_H
#ifndef __TEXTUREMANAGER_H
    #include "TextureManager.h"
#endif // TEXTUREMANAGER_H
#ifndef __GAMEOBJECT_H
    #include "GameObject.h"
#endif // _GAMEOBJECT_H
#ifndef __PLAYER_H
    #include "Player.h"
#endif // _PLAYER_H
#ifndef __ENEMY_H
    #include "Enemy.h"
#endif // __ENEMY_H
#ifndef __sgame_h
    #define __sgame_h 1

class skeletal_game{
    SDL_Window *gwin;
    SDL_Renderer *gren;
    bool run;
    GameObject* g_go;
    GameObject* g_player;
    GameObject* g_enemy;
    std::vector<GameObject*> g_game_objects;
  public:
	skeletal_game();
//	~skeletal_game();
	// simply set the running variable to true
	bool init(const char*, int, int, int, int, int);
	void draw();
	void render();
	void update();
	void handleEvents();
	void clean();
	// a function to access the private running variable
	bool getrun(){
		return(run);
	}
};

#endif // _sgame_h
