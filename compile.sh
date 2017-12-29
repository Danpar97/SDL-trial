#!/bin/bash

#FILE_PATH='/home/danish/Repositories/SDL-trial/source/'
#$C_TARGETS=$('/home/danish/Repositories/SDL-trial/source/experimental.cpp')

set -e    # halt on first error

# use 'g++' as the compiler
CPP='g++'

# be aggressive about warnings and errors
W_FLAGS='-Wall -Wextra -Werror -Wfatal-errors -Wpedantic -pedantic-errors -std=c++11'
INC_FLAGS='-I/usr/include/SDL2'
SDL_FLAGS='-lSDL2 -lSDL2main -lSDL2_image'

# clear out old object files
rm -f /home/danish/Repositories/SDL-trial/source/*.o

# compile
$CPP $INC_FLAGS -c /home/danish/Repositories/SDL-trial/source/experimental.cpp -o /home/danish/Repositories/SDL-trial/source/experimental.o $W_FLAGS
$CPP -o /home/danish/Repositories/SDL-trial/source/experimental /home/danish/Repositories/SDL-trial/source/experimental.o $SDL_FLAGS $W_FLAGS

# (outdated method) compile from terminal: g++ -o experimental ./experimental.cpp $(pkg-config --cflags --libs SDL2 SDL2main SDL2_image)
# Two step compilation
#g++  -I/usr/include/SDL2 -c /home/danish/Repositories/SDL-trial/source/experimental.cpp -o /home/danish/Repositories/SDL-trial/source/experimental.o
#g++  -o /home/danish/Repositories/SDL-trial/source/experimental /home/danish/Repositories/SDL-trial/source/experimental.o  -lSDL2 -lSDL2main -lSDL2_image
