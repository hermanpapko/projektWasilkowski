#ifndef GAME_H
#define GAME_H

#include <string>

class Game {
public:
    Game();
    ~Game();

    void run();

private:
    void processInput();
    void update();
    void render();
    void clearConsole();

    bool m_isRunning;
    std::string m_input;
    std::string m_lastAction;
};

#endif
