
#include "GuessNumberGameWindow.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <random>

GuessNumberGameWindow::GuessNumberGameWindow(int id, int height, int width, bool areAdministratorRightsGranted, Settings* settings)//1//210647
    : GameWindow(id, height, width, areAdministratorRightsGranted, settings) {//1//210647
    std::random_device rd;//1//210647
    std::uniform_int_distribution distribution(1, 100);//1//210647
    targetNumber = distribution(rd);//1//210647
}//210647

void GuessNumberGameWindow::doAction() {//1//210647
    doWork();//1//210647
    int memoryNeeded = calculateMemoryNeeded();//1//210647
    std::cout << "Memory Needed: " << memoryNeeded << " MB" << std::endl;//1//210647

    int attempts = 0;//1//210647
    bool isGuessed = false;//1//210647

    std::cout << "A number between 1 and 100." << std::endl;//1//210647

    while (!isGuessed && attempts < 2) {//1//210647
        int guess;//1//210647

        std::cout << "Enter your guess: ";//1//210647
        std::cin >> guess;//1//210647
        attempts++;//1//210647

        if (guess < targetNumber) {//1//210647
            std::cout << "Too low. Try again." << std::endl;//1//210647
        }//210647
        else if (guess > targetNumber) {//1//210647
            std::cout << "Too high. Try again." << std::endl;//1//210647
        }//1//210647
        else {//1//210647
            std::cout << "Congratulations! You guessed the number in " << attempts << " attempts." << std::endl;//1//210647
            isGuessed = true;//1//210647
        }//1//210647
    }//1//210647

    if (!isGuessed) {
        std::cout << "Sorry, you're out of attempts. The number was " << targetNumber << "." << std::endl;//1//210647
    }
}

int GuessNumberGameWindow::calculateMemoryNeeded() const {//1//210647
    return getSettings()->getSetting3() * getSettings()->getSetting4();//1//210647
}
