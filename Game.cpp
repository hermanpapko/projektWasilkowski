#include "Game.h"
#include <iostream>
#include <random>
#include <algorithm>

Game::Game() : m_isRunning(true), m_currentCommand(Command::NONE), m_lastAction("None"), m_map(20, 10) {
    m_player = std::make_unique<Player>(1, 1, "Hero");
    spawnEnemies(3);
}

Game::~Game() {}

void Game::run() {
    clearConsole();
    std::cout << "Game Started!" << std::endl;
    std::cout << "Controls: WASD to move, Q to quit." << std::endl;

    while (m_isRunning) {
        m_currentCommand = m_inputHandler.handleInput();
        update();
        render();
    }

    std::cout << "Game Over. Goodbye!" << std::endl;
}

void Game::spawnEnemies(int count) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> disX(0, m_map.getWidth() - 1);
    std::uniform_int_distribution<> disY(0, m_map.getHeight() - 1);

    int spawned = 0;
    while (spawned < count) {
        int x = disX(gen);
        int y = disY(gen);

        if (m_map.isWalkable(x, y) && (x != m_player->getX() || y != m_player->getY())) {
            bool occupied = false;
            for (const auto& enemy : m_enemies) {
                if (enemy->getX() == x && enemy->getY() == y) {
                    occupied = true;
                    break;
                }
            }

            if (!occupied) {
                m_enemies.push_back(std::make_unique<Enemy>(x, y));
                spawned++;
            }
        }
    }
}

void Game::update() {
    int nextX = m_player->getX();
    int nextY = m_player->getY();

    switch (m_currentCommand) {
        case Command::UP:
            nextY--;
            m_lastAction = "Moving Up";
            break;
        case Command::DOWN:
            nextY++;
            m_lastAction = "Moving Down";
            break;
        case Command::LEFT:
            nextX--;
            m_lastAction = "Moving Left";
            break;
        case Command::RIGHT:
            nextX++;
            m_lastAction = "Moving Right";
            break;
        case Command::QUIT:
            m_isRunning = false;
            break;
        case Command::NONE:
        default:
            break;
    }

    if (m_currentCommand == Command::NONE || m_currentCommand == Command::QUIT) {
        return;
    }

    bool collision = false;
    for (const auto& enemy : m_enemies) {
        if (enemy->getX() == nextX && enemy->getY() == nextY) {
            collision = true;
            
            // Combat logic
            int playerDamage = m_player->getDamage();
            int enemyDamage = enemy->getDamage();
            
            enemy->takeDamage(playerDamage);
            m_player->takeDamage(enemyDamage);
            
            m_lastAction = "Player hits Enemy for " + std::to_string(playerDamage) + 
                           "! Enemy hits back for " + std::to_string(enemyDamage) + "!";
            break;
        }
    }

    if (!collision) {
        if (m_map.isWalkable(nextX, nextY)) {
            m_player->setPosition(nextX, nextY);
        } else {
            m_lastAction += " (Blocked!)";
        }
    }

    // Basic Enemy AI: Move enemies if player did something (Turn-based)
    for (auto& enemy : m_enemies) {
        if (enemy->moveRandomly(m_map, m_enemies, *m_player)) {
            m_lastAction = "Enemy attacks Player! Both take damage.";
        }
    }

    // Remove dead enemies
    m_enemies.erase(
        std::remove_if(m_enemies.begin(), m_enemies.end(),
            [](const std::unique_ptr<Enemy>& enemy) { return !enemy->isAlive(); }),
        m_enemies.end()
    );
}

void Game::render() {
    if (m_isRunning) {
        // Move cursor to 1,1 instead of clearing the whole screen
        std::cout << "\033[H"; 
        
        std::vector<RenderEntity> entities;
        entities.push_back({m_player->getX(), m_player->getY(), m_player->getSymbol()});
        for (const auto& enemy : m_enemies) {
            entities.push_back({enemy->getX(), enemy->getY(), enemy->getSymbol()});
        }

        std::string frame = "--- Game Engine (Refactored) ---\n";
        frame += m_map.render(entities);
        frame += "Action:   " + m_lastAction + "                \n"; // Padding to clear old text
        frame += "--------------------------------\n";
        frame += "Press Q to quit.                \n";
        
        std::cout << frame << std::flush;
    }
}

void Game::clearConsole() {
    // Initial clear only
    std::cout << "\033[2J\033[H";
}
