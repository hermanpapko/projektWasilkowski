cmake_minimum_required(VERSION 4.2)
project(projektWasilkowski)

set(CMAKE_CXX_STANDARD 20)

include_directories(Core Entities World)

# Main game executable
add_executable(projektWasilkowski 
    Core/main.cpp 
    Core/Game.cpp Core/Game.h 
    Core/InputHandler.cpp Core/InputHandler.h 
    Entities/Entity.cpp Entities/Entity.h 
    Entities/Player.cpp Entities/Player.h 
    Entities/Enemy.cpp Entities/Enemy.h
    World/Map.cpp World/Map.h
)

# Test executable
add_executable(run_tests 
    tests.cpp 
    Entities/Entity.cpp 
    Entities/Player.cpp 
    Entities/Enemy.cpp
    World/Map.cpp World/Map.h
)
