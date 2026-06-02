#ifndef GAME_H
#define GAME_H

#include "InputHandler.h"
#include "Map.h"
#include "Enemy.h"
#include "Player.h"
#include <string>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

/**
 * @class Game
 * @brief Main controller for the game loop, rendering, and logic.
 */
class Game {
public:
    Game();
    ~Game();

    /**
     * @brief Starts and maintains the main game loop.
     */
    void run();

private:
    /**
     * @brief Processes game logic for the current frame.
     */
    void update();

    /**
     * @brief Renders all game elements to the window.
     */
    void render();

    /**
     * @brief Spawns a specified number of enemies at random valid locations.
     */
    void spawnEnemies(int count);

    /**
     * @brief Initializes the vertex array for map rendering optimization.
     */
    void initMapVertices();

    bool m_isRunning;
    bool m_isGameOver;
    InputHandler m_inputHandler;
    Command m_currentCommand;
    std::vector<std::string> m_eventLog;
    void addLog(const std::string& message);
    Map m_map;
    std::unique_ptr<Player> m_player;
    std::vector<std::unique_ptr<Enemy>> m_enemies;

    sf::RenderWindow m_window;
    sf::Font m_font;
    bool m_fontLoaded;
    int m_cellSize;

    sf::VertexArray m_mapVertices;
};

#endif
