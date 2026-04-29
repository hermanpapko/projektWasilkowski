#include "Game.h"
#include <iostream>

Game::Game() : m_isRunning(true), m_currentCommand(Command::NONE), m_lastAction("None") {}

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
    switch (m_currentCommand) {
        case Command::UP:
            m_lastAction = "Moving Up";
            break;
        case Command::DOWN:
            m_lastAction = "Moving Down";
            break;
        case Command::LEFT:
            m_lastAction = "Moving Left";
            break;
        case Command::RIGHT:
            m_lastAction = "Moving Right";
            break;
        case Command::QUIT:
            m_isRunning = false;
            break;
        case Command::NONE:
        default:
            break;
    }
}

void Game::render() {
    if (m_isRunning) {
        clearConsole();
        std::cout << "--- Game Engine (Refactored) ---" << std::endl;
        std::cout << "Action:   " << m_lastAction << std::endl;
        std::cout << "--------------------------------" << std::endl;
        std::cout << "Press Q to quit." << std::endl;
    }
}

void Game::clearConsole() {
    std::cout << "\033[2J\033[1;1H";
}
