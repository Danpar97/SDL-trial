#ifndef  _GLIBCXX_IOSTREAM
    #include <iostream>
#endif // check iostream & include
#ifndef  _SDL_h
    #include <SDL2/SDL.h>
#endif // check SDL & include
#ifndef TEXTUREMANAGER_H_INCLUDED
    #include "TextureManager.h"
#endif // TEXTUREMANAGER_H_INCLUDED
#ifndef _sgame_h
    #define _sgame_h 1

//compile from terminal: g++ -o test ./test.cpp $(pkg-config --cflags --libs sdl2)

class skeletal_game{
    SDL_Window *gwin;
    SDL_Renderer *gren;
    SDL_Texture *gtex;
    SDL_Rect src, dest;
    bool run;
    int current_frame;
    TextureManager texture_manager;
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
