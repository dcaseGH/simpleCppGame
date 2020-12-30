#!/usr/bin/env bash

# Clean
rm *.o
rm sfml-app

# use -I if non standard path
g++ --std=c++17 -c main.cpp Team.cpp Player.cpp coreFunctions.cpp

# use -L if needed for path
g++ --std=c++17 main.o Team.o Player.o coreFunctions.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

# run
./sfml-app
