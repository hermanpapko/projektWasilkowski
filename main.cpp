#include <iostream>
#include <string>

void clearConsole() {
    // ANSI escape codes: \033[2J clear screen, \033[1;1H move cursor to top-left
    std::cout << "\033[2J\033[1;1H";
}

int main() {
    bool isRunning = true;
    std::string input;

    std::cout << "Game Started! Press 'q' to quit." << std::endl;

    while (isRunning) {
        std::cout << "> ";
        std::cin >> input;

        if (input == "q") {
            isRunning = false;
        }

        if (isRunning) {
            clearConsole();
            std::cout << "You entered: " << input << std::endl;
            std::cout << "Updating game state..." << std::endl;
            std::cout << "Rendering..." << std::endl;
        }
    }

    std::cout << "Game Over. Goodbye!" << std::endl;

    return 0;
}
