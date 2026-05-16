#include "Game.h"
#include <iostream>
#include <random>
#include <algorithm>

Game::Game() : m_isRunning(true), m_currentCommand(Command::NONE), m_map(20, 10) {
    m_player = std::make_unique<Player>(1, 1, "Hero");
    spawnEnemies(3);
    addLog("Game Started! Controls: WASD to move, Q to quit.");
}

Game::~Game() {}

void Game::addLog(const std::string& message) {
    m_eventLog.push_back(message);
    if (m_eventLog.size() > 5) {
        m_eventLog.erase(m_eventLog.begin());
    }
}

void Game::run() {
    clearConsole();

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
            break;
        case Command::DOWN:
            nextY++;
            break;
        case Command::LEFT:
            nextX--;
            break;
        case Command::RIGHT:
            nextX++;
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
            
            addLog("Player hits Enemy for " + std::to_string(playerDamage) + 
                   "! Enemy hits back for " + std::to_string(enemyDamage) + "!");
            break;
        }
    }

    if (!collision) {
        if (m_map.isWalkable(nextX, nextY)) {
            m_player->setPosition(nextX, nextY);
        } else {
            addLog("Player movement blocked!");
        }
    }

    // Basic Enemy AI: Move enemies if player did something (Turn-based)
    for (auto& enemy : m_enemies) {
        if (enemy->moveRandomly(m_map, m_enemies, *m_player)) {
            addLog("Enemy attacks Player! Both take damage.");
        }
    }

    // Remove dead enemies
    m_enemies.erase(
        std::remove_if(m_enemies.begin(), m_enemies.end(),
            [this](const std::unique_ptr<Enemy>& enemy) { 
                if (!enemy->isAlive()) {
                    addLog("Enemy died! +10 Score");
                    m_player->addScore(10);
                    return true;
                }
                return false;
            }),
        m_enemies.end()
    );

    // Check Player Death
    if (!m_player->isAlive()) {
        m_isRunning = false;
        addLog("PLAYER DIED! Game Over.");
    }
}

void Game::render() {
    // Move cursor to 1,1 instead of clearing the whole screen
    std::cout << "\033[H"; 
    
    std::vector<RenderEntity> entities;
    if (m_player->isAlive()) {
        entities.push_back({m_player->getX(), m_player->getY(), m_player->getSymbol()});
    }
    for (const auto& enemy : m_enemies) {
        entities.push_back({enemy->getX(), enemy->getY(), enemy->getSymbol()});
    }

    std::string frame = "--- Game Engine (Combat) ---\n";
    
    // HUD
    frame += "Hero: " + m_player->getName() + " | HP: " + std::to_string(m_player->getHP()) + 
             " | Level: " + std::to_string(m_player->getLevel()) + 
             " | Score: " + std::to_string(m_player->getScore()) + "          \n";
    frame += "--------------------------------\n";

    frame += m_map.render(entities);
    
    frame += "--- Event Log ---\n";
    for (const auto& log : m_eventLog) {
        frame += log + "                                        \n"; // Padding
    }
    frame += "--------------------------------\n";
    
    if (!m_player->isAlive()) {
        frame += "        GAME OVER!          \n";
        frame += "   The Hero has fallen...   \n";
    } else {
        frame += "Press Q to quit.                \n";
    }
    
    std::cout << frame << std::flush;
}

void Game::clearConsole() {
    // Initial clear only
    std::cout << "\033[2J\033[H";
}
