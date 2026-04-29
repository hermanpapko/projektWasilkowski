#include "InputHandler.h"
#include <iostream>

#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#include <stdio.h>

/* Functional equivalent of _getch() for terminal-based systems */
int getch() {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
#endif

Command InputHandler::handleInput() {
    int ch;
#ifdef _WIN32
    ch = _getch();
#else
    ch = getch();
#endif

    switch (ch) {
        case 'w': case 'W': return Command::UP;
        case 's': case 'S': return Command::DOWN;
        case 'a': case 'A': return Command::LEFT;
        case 'd': case 'D': return Command::RIGHT;
        case 'q': case 'Q': return Command::QUIT;
        default: return Command::NONE;
    }
}
