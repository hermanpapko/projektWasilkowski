#include "Game.h"
#include <iostream>

Game::Game() : m_isRunning(true), m_currentCommand(Command::NONE), m_lastAction("None"), m_map(20, 10), m_playerX(1), m_playerY(1) {}

Game::~Game() {}

void Game::run() {
    std::cout << "Game Started!" << std::endl;
    std::cout << "Controls: WASD to move, Q to quit." << std::endl;

    while (m_isRunning) {
        m_currentCommand = m_inputHandler.handleInput();
        update();
        render();
    }

    std::cout << "Game Over. Goodbye!" << std::endl;
}

void Game::update() {
    int nextX = m_playerX;
    int nextY = m_playerY;

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

    if (m_map.isWalkable(nextX, nextY)) {
        m_playerX = nextX;
        m_playerY = nextY;
    } else if (m_currentCommand != Command::NONE && m_currentCommand != Command::QUIT) {
        m_lastAction += " (Blocked!)";
    }
}

void Game::render() {
    if (m_isRunning) {
        clearConsole();
        std::cout << "--- Game Engine (Refactored) ---" << std::endl;
        m_map.render(m_playerX, m_playerY);
        std::cout << "Action:   " << m_lastAction << std::endl;
        std::cout << "--------------------------------" << std::endl;
        std::cout << "Press Q to quit." << std::endl;
    }
}

void Game::clearConsole() {
    std::cout << "\033[2J\033[1;1H";
}
