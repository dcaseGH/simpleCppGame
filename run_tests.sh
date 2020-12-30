#!/usr/bin/env bash

rm tests.exe

# make in 1 step
g++ --std=c++17 tests.cpp Player.cpp Team.cpp Game.cpp coreFunctions.cpp -o tests.exe  -lsfml-graphics -lsfml-window -lsfml-system

# run (expect all to pass?)
./tests.exe
