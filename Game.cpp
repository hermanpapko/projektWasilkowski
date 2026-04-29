#include "Game.h"
#include <iostream>

Game::Game() : m_isRunning(true), m_input(""), m_lastAction("None") {}

Game::~Game() {}

void Game::run() {
    std::cout << "Game Started!" << std::endl;
    std::cout << "Controls: W (Up), A (Left), S (Down), D (Right), Q (Quit)" << std::endl;
    std::cout << "Press Enter after each key (Temporary)" << std::endl;

    while (m_isRunning) {
        processInput();
        update();
        render();
    }

    std::cout << "Game Over. Goodbye!" << std::endl;
}

void Game::processInput() {
    std::cout << "Input: ";
    std::cin >> m_input;
}

void Game::update() {
    if (m_input == "q" || m_input == "Q") {
        m_isRunning = false;
    } else if (m_input == "w" || m_input == "W") {
        m_lastAction = "Moving Up";
    } else if (m_input == "s" || m_input == "S") {
        m_lastAction = "Moving Down";
    } else if (m_input == "a" || m_input == "A") {
        m_lastAction = "Moving Left";
    } else if (m_input == "d" || m_input == "D") {
        m_lastAction = "Moving Right";
    }
}

void Game::render() {
    if (m_isRunning) {
        clearConsole();
        std::cout << "--- Game Engine ---" << std::endl;
        std::cout << "Last Key: " << m_input << std::endl;
        std::cout << "Action:   " << m_lastAction << std::endl;
        std::cout << "-------------------" << std::endl;
        std::cout << "Press Q to quit." << std::endl;
    }
}

void Game::clearConsole() {
    std::cout << "\033[2J\033[1;1H";
}
