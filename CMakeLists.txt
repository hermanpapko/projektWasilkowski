cmake_minimum_required(VERSION 4.2)
project(projektWasilkowski)

set(CMAKE_CXX_STANDARD 20)

# Main game executable
add_executable(projektWasilkowski 
    main.cpp 
    Game.cpp Game.h 
    InputHandler.cpp InputHandler.h 
    Entity.cpp Entity.h 
    Player.cpp Player.h 
    Enemy.cpp Enemy.h
)

# Test executable
add_executable(run_tests 
    tests.cpp 
    Entity.cpp 
    Player.cpp 
    Enemy.cpp
)
