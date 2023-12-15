#include "GameWindow.h"
#include "Settings.h"
#include "RockPaperScissorsGameWindow.h"
#include "GuessNumberGameWindow.h"
#include <iostream>

void playRockPaperScissors(Settings& settings) {//1
    RockPaperScissorsGameWindow rockPaperScissors(1, 800, 600, true, &settings);//1
    while (true) {//1
        rockPaperScissors.doAction();//1
        int playAgain;//1
        std::cout << "Play again? (1 for yes, 0 for no): ";//1
        std::cin >> playAgain;//1
        if (playAgain == 0) {//1
            break;//1
        }//1
    }//1
}

void playGuessNumber(Settings& settings) {//1
    GuessNumberGameWindow guessNumber(2, 800, 600, true, &settings);//1
    while (true) {//1
        guessNumber.doAction();//1
        int playAgain;//1
        std::cout << "Play again? (1 for yes, 0 for no): ";//1
        std::cin >> playAgain;//1
        if (playAgain == 0) {//1
            break;//1
        }//1
    }
}

int main() {
    Settings rockPaperScissorsSettings(1, 2, 3, 4, 5);//1
    Settings guessNumberSettings(6, 7, 8, 9, 10);//1

    int choice;//1

    do {
        std::cout << "Choose a game:" << std::endl;//1
        std::cout << "1. Rock-Paper-Scissors" << std::endl;//1
        std::cout << "2. Guess the Number" << std::endl;//1
        std::cout << "3. Exit" << std::endl;//1
        std::cout << "Enter your choice: ";//1
        std::cin >> choice;//1

        switch (choice) {//1
        case 1://1
            playRockPaperScissors(rockPaperScissorsSettings);//1
            break;//1

        case 2://1
            playGuessNumber(guessNumberSettings);//1
            break;//1

        case 3:
            std::cout << "Exiting the program." << std::endl;//1
            break;//1

        default:
            std::cout << "Invalid choice. Please try again." << std::endl;//1
            break;//1
        }

    } while (choice != 3);

    return 0;
}
