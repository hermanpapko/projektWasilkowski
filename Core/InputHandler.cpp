#include "InputHandler.h"

Command InputHandler::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
            case sf::Keyboard::W:
            case sf::Keyboard::Up:
                return Command::UP;
            case sf::Keyboard::S:
            case sf::Keyboard::Down:
                return Command::DOWN;
            case sf::Keyboard::A:
            case sf::Keyboard::Left:
                return Command::LEFT;
            case sf::Keyboard::D:
            case sf::Keyboard::Right:
                return Command::RIGHT;
            case sf::Keyboard::Q:
            case sf::Keyboard::Escape:
                return Command::QUIT;
            default:
                return Command::NONE;
        }
    }
    return Command::NONE;
}
