
#include "GuessNumberGameWindow.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <random>

GuessNumberGameWindow::GuessNumberGameWindow(int id, int height, int width, bool areAdministratorRightsGranted, Settings* settings)//1
    : GameWindow(id, height, width, areAdministratorRightsGranted, settings) {//1
    std::random_device rd;//1
    std::uniform_int_distribution distribution(1, 100);//1
    targetNumber = distribution(rd);//1
}

void GuessNumberGameWindow::doAction() {//1
    doWork();//1
    int memoryNeeded = calculateMemoryNeeded();//1
    std::cout << "Memory Needed: " << memoryNeeded << " MB" << std::endl;//1

    int attempts = 0;//1
    bool isGuessed = false;//1

    std::cout << "A number between 1 and 100." << std::endl;//1

    while (!isGuessed && attempts < 2) {//1
        int guess;//1

        std::cout << "Enter your guess: ";//1
        std::cin >> guess;//1
        attempts++;//1

        if (guess < targetNumber) {//1
            std::cout << "Too low. Try again." << std::endl;//1
        }
        else if (guess > targetNumber) {//1
            std::cout << "Too high. Try again." << std::endl;//1
        }//1
        else {//1
            std::cout << "Congratulations! You guessed the number in " << attempts << " attempts." << std::endl;//1
            isGuessed = true;//1
        }//1
    }//1

    if (!isGuessed) {
        std::cout << "Sorry, you're out of attempts. The number was " << targetNumber << "." << std::endl;//1
    }
}

int GuessNumberGameWindow::calculateMemoryNeeded() const {//1
    return getSettings()->getSetting3() * getSettings()->getSetting4();//1
}
