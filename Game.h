#ifndef GAME_H
#define GAME_H

#include "InputHandler.h"
#include "Map.h"
#include "Enemy.h"
#include "Player.h"
#include <string>
#include <vector>
#include <memory>

class Game {
public:
    Game();
    ~Game();

    void run();

private:
    void update();
    void render();
    void clearConsole();
    void spawnEnemies(int count);

    bool m_isRunning;
    InputHandler m_inputHandler;
    Command m_currentCommand;
    std::vector<std::string> m_eventLog;
    void addLog(const std::string& message);
    Map m_map;
    std::unique_ptr<Player> m_player;
    std::vector<std::unique_ptr<Enemy>> m_enemies;
};

#endif
