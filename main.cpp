#include <iostream>
#include <string>

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
            std::cout << "You entered: " << input << std::endl;
            std::cout << "Updating game state..." << std::endl;
            std::cout << "Rendering..." << std::endl;
        }
    }

    std::cout << "Game Over. Goodbye!" << std::endl;

    return 0;
}
