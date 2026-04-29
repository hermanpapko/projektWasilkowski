#include "Game.h"
#include <iostream>

Game::Game() : m_isRunning(true), m_input("") {}

Game::~Game() {}

void Game::run() {
    std::cout << "Game Started! Press 'q' to quit." << std::endl;

    while (m_isRunning) {
        processInput();
        update();
        render();
    }

    std::cout << "Game Over. Goodbye!" << std::endl;
}

void Game::processInput() {
    std::cout << "> ";
    std::cin >> m_input;
}

void Game::update() {
    if (m_input == "q") {
        m_isRunning = false;
    }
}

void Game::render() {
    if (m_isRunning) {
        clearConsole();
        std::cout << "You entered: " << m_input << std::endl;
        std::cout << "Updating game state..." << std::endl;
        std::cout << "Rendering from Game class..." << std::endl;
    }
}

void Game::clearConsole() {
    std::cout << "\033[2J\033[1;1H";
}
