#include "GameWindow.h"
#include "Settings.h"
#include "RockPaperScissorsGameWindow.h"
#include "GuessNumberGameWindow.h"
#include <iostream>

void playRockPaperScissors(Settings& settings) {
    RockPaperScissorsGameWindow rockPaperScissors(1, 800, 600, true, &settings);
    while (true) {
        rockPaperScissors.doAction();
        int playAgain;
        std::cout << "Play again? (1 for yes, 0 for no): ";
        std::cin >> playAgain;
        if (playAgain == 0) {
            break;
        }
    }
}

void playGuessNumber(Settings& settings) {
    GuessNumberGameWindow guessNumber(2, 800, 600, true, &settings);
    while (true) {
        guessNumber.doAction();
        int playAgain;
        std::cout << "Play again? (1 for yes, 0 for no): ";
        std::cin >> playAgain;
        if (playAgain == 0) {
            break;
        }
    }
}

int main() {
    Settings rockPaperScissorsSettings(1, 2, 3, 4, 5);
    Settings guessNumberSettings(6, 7, 8, 9, 10);

    int choice;

    do {
        std::cout << "Choose a game:" << std::endl;
        std::cout << "1. Rock-Paper-Scissors" << std::endl;
        std::cout << "2. Guess the Number" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            playRockPaperScissors(rockPaperScissorsSettings);
            break;

        case 2:
            playGuessNumber(guessNumberSettings);
            break;

        case 3:
            std::cout << "Exiting the program." << std::endl;
            break;

        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }

    } while (choice != 3);

    return 0;
}
