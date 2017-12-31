#ifndef  _GLIBCXX_IOSTREAM
    #include <iostream>
#endif // check iostream & include
#ifndef  _SDL_h
    #include <SDL2/SDL.h>
#endif // check SDL & include
#ifndef TEXTUREMANAGER_H
    #include "TextureManager.h"
#endif // TEXTUREMANAGER_H
#ifndef _GAMEOBJECT_H
    #include "GameObject.h"
#endif // _GAMEOBJECT_H
#ifndef _PLAYER_H
    #include "Player.h"
#endif // _PLAYER_H
#ifndef _sgame_h
    #define _sgame_h 1

//compile from terminal: g++ -o test ./test.cpp $(pkg-config --cflags --libs sdl2)

class skeletal_game{
    SDL_Window *gwin;
    SDL_Renderer *gren;
    bool run;
    GameObject g_go;
    Player g_player;
  public:
	skeletal_game();
//	~skeletal_game();
	// simply set the running variable to true
	bool init(const char*, int, int, int, int, int);
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
