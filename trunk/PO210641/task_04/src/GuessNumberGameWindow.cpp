#include "GuessNumberGameWindow.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <random>

GuessNumberGameWindow::GuessNumberGameWindow(int id, int height, int width, bool areAdministratorRightsGranted, Settings* settings)
    : GameWindow(id, height, width, areAdministratorRightsGranted, settings) {
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_int_distribution distribution(1, 100);
    targetNumber = distribution(generator);
}

void GuessNumberGameWindow::doAction() {
    doWork();
    int memoryNeeded = calculateMemoryNeeded();
    std::cout << "Memory Needed: " << memoryNeeded << " MB" << std::endl;

    int attempts = 0;
    bool isGuessed = false;

    std::cout << "A number between 1 and 100." << std::endl;

    while (!isGuessed && attempts < 2) {
        int guess;

        std::cout << "Enter your guess: ";
        std::cin >> guess;
        attempts++;

        if (guess < targetNumber) {
            std::cout << "Too low. Try again." << std::endl;
        }
        else if (guess > targetNumber) {
            std::cout << "Too high. Try again." << std::endl;
        }
        else {
            std::cout << "Congratulations! You guessed the number in " << attempts << " attempts." << std::endl;
            isGuessed = true;
        }
    }

    if (!isGuessed) {
        std::cout << "Sorry, you're out of attempts. The number was " << targetNumber << "." << std::endl;
    }
}

int GuessNumberGameWindow::calculateMemoryNeeded() const {
    return getSettings()->getSetting3() * getSettings()->getSetting4();
}
