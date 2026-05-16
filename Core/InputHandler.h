#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <string>

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
    Command handleInput();
};

#endif
