cmake_minimum_required(VERSION 3.14)
project(projektWasilkowski)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
)
# Force SFML to build statically so we don't need DLLs
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build shared libraries" FORCE)
FetchContent_MakeAvailable(SFML)

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

target_link_libraries(projektWasilkowski PRIVATE sfml-graphics sfml-window sfml-system)

# Test executable
add_executable(run_tests 
    tests.cpp 
    Entities/Entity.cpp 
    Entities/Player.cpp 
    Entities/Enemy.cpp
    World/Map.cpp World/Map.h
)
