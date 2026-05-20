#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <SFML/Window/Event.hpp>

enum class Command {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    QUIT,
    NONE
};

class InputHandler {
public:
    Command handleEvent(const sf::Event& event);
};

#endif
