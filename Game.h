#ifndef GAME_H
#define GAME_H

#include "InputHandler.h"
#include "Map.h"
#include <string>

class Game {
public:
    Game();
    ~Game();

    void run();

private:
    void update();
    void render();
    void clearConsole();

    bool m_isRunning;
    InputHandler m_inputHandler;
    Command m_currentCommand;
    std::string m_lastAction;
    Map m_map;
};

#endif
