#!/bin/bash

echo "Enter filename: ";
read $FILE_NAME;

set -e    # halt on first error

# use 'g++' as the compiler
CPP=g++

# be aggressive about warnings and errors
FLAGS="-lSDL2 -lSDL2main -lSDL2_image -Wall -Wextra -Werror -Wfatal-errors -Wpedantic -pedantic-errors"

# clear out old object files
rm -f *.o

# compile

$CPP $FLAGS -o binary.out $FILE_NAME

# compile from terminal: g++ -o experimental ./experimental.cpp $(pkg-config --cflags --libs SDL2 SDL2main SDL2_image)
# g++  -I/usr/include/SDL2 -c /home/danish/Repositories/SDL-trial/source/experimental.cpp -o /home/danish/Repositories/SDL-trial/source/experimental.o
# g++  -o /home/danish/Repositories/SDL-trial/source/experimental /home/danish/Repositories/SDL-trial/source/experimental.o  -lSDL2 -lSDL2main -lSDL2_image
