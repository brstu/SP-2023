#include "GameWindow.h"
#include "Settings.h"
#include "RockPaperScissorsGameWindow.h"
#include "GuessNumberGameWindow.h"
#include <iostream>

void playRockPaperScissors(Settings& settings) {//1//210647
    RockPaperScissorsGameWindow rockPaperScissors(1, 800, 600, true, &settings);//1//210647
    while (true) {//1//210647
        rockPaperScissors.doAction();//1//210647
        int playAgain;//1//210647
        std::cout << "Play again? (1 for yes, 0 for no): ";//1//210647
        std::cin >> playAgain;//1//210647
        if (playAgain == 0) {//1//210647
            break;//1//210647
        }//1//210647
    }//1//210647
}//210647

void playGuessNumber(Settings& settings) {//1//210647
    GuessNumberGameWindow guessNumber(2, 800, 600, true, &settings);//1//210647
    while (true) {//1//210647
        guessNumber.doAction();//1//210647
        int playAgain;//1//210647
        std::cout << "Play again? (1 for yes, 0 for no): ";//1//210647
        std::cin >> playAgain;//1//210647
        if (playAgain == 0) {//1//210647
            break;//1//210647
        }//1//210647
    }//210647
}//210647

int main() {//210647
    Settings rockPaperScissorsSettings(1, 2, 3, 4, 5);//1//210647
    Settings guessNumberSettings(6, 7, 8, 9, 10);//1//210647

    int choice;//1//210647

    do {
        std::cout << "Choose a game:" << std::endl;//1//210647
        std::cout << "1. Rock-Paper-Scissors" << std::endl;//1//210647
        std::cout << "2. Guess the Number" << std::endl;//1//210647
        std::cout << "3. Exit" << std::endl;//1//210647
        std::cout << "Enter your choice: ";//1//210647
        std::cin >> choice;//1//210647

        switch (choice) {//1//210647
        case 1://1//210647
            playRockPaperScissors(rockPaperScissorsSettings);//1//210647
            break;//1//210647

        case 2://1//210647
            playGuessNumber(guessNumberSettings);//1//210647
            break;//1//210647

        case 3://210647
            std::cout << "Exiting the program." << std::endl;//1//210647
            break;//1//210647

        default://210647
            std::cout << "Invalid choice. Please try again." << std::endl;//1//210647
            break;//1//210647
        }

    } while (choice != 3);//210647

    return 0;//210647
}
