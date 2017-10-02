#ifndef  _GLIBCXX_IOSTREAM
    #include <iostream>
#endif // check iostream & include
#ifndef  _SDL_h
    #include <SDL2/SDL.h>
#endif // check SDL & include
#ifndef _sgame_h
    #define _sgame_h 1
#endif // _sgame_h

//compile from terminal: g++ -o test ./test.cpp $(pkg-config --cflags --libs sdl2)

class skeletal_game{
    SDL_Window *gwin;
    SDL_Renderer *gren;
    SDL_Texture *gtex;
    SDL_Rect src, dest;
    bool run;
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
