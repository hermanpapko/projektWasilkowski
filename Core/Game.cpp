#include "Game.h"
#include <iostream>
#include <random>
#include <algorithm>

Game::Game() : m_isRunning(true), m_currentCommand(Command::NONE), m_map(20, 10),
               m_window(sf::VideoMode(800, 600), "Projekt Wasilkowski"),
               m_cellSize(32) {
    m_player = std::make_unique<Player>(1, 1, "Hero");
    spawnEnemies(3);
    
    m_fontLoaded = m_font.loadFromFile("C:/Windows/Fonts/arial.ttf");
    if (!m_fontLoaded) {
        std::cerr << "Warning: Could not load arial.ttf font." << std::endl;
    }

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
    while (m_isRunning && m_window.isOpen()) {
        sf::Event event;
        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                m_window.close();
                m_isRunning = false;
            }
            
            Command cmd = m_inputHandler.handleEvent(event);
            if (cmd != Command::NONE) {
                m_currentCommand = cmd;
                update();
            }
        }
        
        if (m_window.isOpen()) {
            render();
        }
    }
    
    if (m_window.isOpen()) {
        m_window.close();
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

/**
 * Handles the main game logic including player movement, collision detection, 
 * combat resolution, and basic turn-based enemy AI updates.
 */
void Game::update() {
    int nextX = m_player->getX();
    int nextY = m_player->getY();

    switch (m_currentCommand) {
        case Command::UP:    nextY--; break;
        case Command::DOWN:  nextY++; break;
        case Command::LEFT:  nextX--; break;
        case Command::RIGHT: nextX++; break;
        case Command::QUIT:  m_isRunning = false; return;
        case Command::NONE:
        default: return;
    }

    bool collision = false;
    for (const auto& enemy : m_enemies) {
        if (enemy->getX() == nextX && enemy->getY() == nextY) {
            collision = true;
            
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
            
            if (m_map.isExit(nextX, nextY)) {
                m_isRunning = false;
                addLog("VICTORY! You reached the exit!");
            }
        } else {
            addLog("Player movement blocked!");
        }
    }

    for (auto& enemy : m_enemies) {
        if (enemy->moveRandomly(m_map, m_enemies, *m_player)) {
            addLog("Enemy attacks Player! Both take damage.");
        }
    }

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

    if (!m_player->isAlive()) {
        m_isRunning = false;
        addLog("PLAYER DIED! Game Over.");
    }
}

void Game::render() {
    m_window.clear(sf::Color(20, 20, 20));

    int offsetX = 20;
    int offsetY = 60; // Leave space for HUD at the top

    // Draw Map
    for (int y = 0; y < m_map.getHeight(); ++y) {
        for (int x = 0; x < m_map.getWidth(); ++x) {
            char cell = m_map.getCell(x, y);
            sf::RectangleShape rect(sf::Vector2f(m_cellSize - 1.0f, m_cellSize - 1.0f));
            rect.setPosition(offsetX + x * m_cellSize, offsetY + y * m_cellSize);

            if (cell == '#') rect.setFillColor(sf::Color(100, 100, 100));
            else if (cell == '.') rect.setFillColor(sf::Color(40, 40, 40));
            else if (cell == '>') rect.setFillColor(sf::Color::Yellow);
            else rect.setFillColor(sf::Color::Black);

            m_window.draw(rect);
        }
    }

    // Draw Entities helper
    auto drawEntity = [&](int x, int y, sf::Color color) {
        sf::RectangleShape rect(sf::Vector2f(m_cellSize - 4.0f, m_cellSize - 4.0f));
        rect.setPosition(offsetX + x * m_cellSize + 2.0f, offsetY + y * m_cellSize + 2.0f);
        rect.setFillColor(color);
        m_window.draw(rect);
    };

    for (const auto& enemy : m_enemies) {
        drawEntity(enemy->getX(), enemy->getY(), sf::Color::Red);
    }

    if (m_player->isAlive()) {
        drawEntity(m_player->getX(), m_player->getY(), sf::Color::Green);
    }

    // Draw Text (HUD and Logs)
    if (m_fontLoaded) {
        sf::Text hudText;
        hudText.setFont(m_font);
        hudText.setCharacterSize(18);
        hudText.setFillColor(sf::Color::White);
        
        std::string hudString = "Hero: " + m_player->getName() + 
                                " | HP: " + std::to_string(m_player->getHP()) + 
                                " | Lvl: " + std::to_string(m_player->getLevel()) + 
                                " | Score: " + std::to_string(m_player->getScore());
        hudText.setString(hudString);
        hudText.setPosition(20, 20);
        m_window.draw(hudText);

        // Draw Logs at the bottom
        int logStartY = offsetY + m_map.getHeight() * m_cellSize + 20;
        sf::Text logText;
        logText.setFont(m_font);
        logText.setCharacterSize(16);
        logText.setFillColor(sf::Color(200, 200, 200));

        for (size_t i = 0; i < m_eventLog.size(); ++i) {
            logText.setString(m_eventLog[i]);
            logText.setPosition(20, logStartY + i * 20);
            m_window.draw(logText);
        }
        
        // Draw End Game / Instructions
        sf::Text statusText;
        statusText.setFont(m_font);
        statusText.setCharacterSize(18);
        statusText.setPosition(400, 20);
        
        if (!m_player->isAlive()) {
            statusText.setFillColor(sf::Color::Red);
            statusText.setString("GAME OVER! The Hero has fallen...");
        } else if (!m_isRunning && m_map.isExit(m_player->getX(), m_player->getY())) {
            statusText.setFillColor(sf::Color::Yellow);
            statusText.setString("VICTORY! You escaped!");
        } else {
            statusText.setFillColor(sf::Color(150, 150, 150));
            statusText.setString("Press Q to quit");
        }
        m_window.draw(statusText);
    }

    m_window.display();
}
