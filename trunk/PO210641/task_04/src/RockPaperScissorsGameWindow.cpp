#include "RockPaperScissorsGameWindow.h"
#include <iostream>
#include <ctime>
#include <random>

using namespace std;

RockPaperScissorsGameWindow::RockPaperScissorsGameWindow(int id, int height, int width, bool areAdministratorRightsGranted, Settings* settings)
    : GameWindow(id, height, width, areAdministratorRightsGranted, settings) {
    std::random_device rd;
    std::uniform_int_distribution distribution(0, 2);
    randomChoicePlayer2 = distribution(rd);
}

void RockPaperScissorsGameWindow::doAction() {
    doWork();
    int memoryNeeded = calculateMemoryNeeded();
    cout << "Memory Needed: " << memoryNeeded << " MB" << endl;

    int player1Choice;
    cout << "Player 1, enter your choice (0 - Rock, 1 - Scissors, 2 - Paper): ";
    cin >> player1Choice;


    string choicePlayer1;
    string choicePlayer2;

    if (player1Choice == 0) {
        choicePlayer1 = "Rock";
    }
    else if (player1Choice == 1) {
        choicePlayer1 = "Scissors";
    }
    else {
        choicePlayer1 = "Paper";
    }

    if (randomChoicePlayer2 == 0) {
        choicePlayer2 = "Rock";
    }
    else if (randomChoicePlayer2 == 1) {
        choicePlayer2 = "Scissors";
    }
    else {
        choicePlayer2 = "Paper";
    }

    cout << "Player 1 chose: " << choicePlayer1 << endl;
    cout << "Player 2 chose: " << choicePlayer2 << endl;

    if (player1Choice == randomChoicePlayer2) {
        cout << "It's a tie!" << endl;
    }
    else if ((player1Choice == 0 && randomChoicePlayer2 == 1) ||
        (player1Choice == 1 && randomChoicePlayer2 == 2) ||
        (player1Choice == 2 && randomChoicePlayer2 == 0)) {
        cout << "Player 1 wins!" << endl;
    }
    else {
        cout << "Player 2 wins!" << endl;
    }
}

int RockPaperScissorsGameWindow::calculateMemoryNeeded() const {
    return getSettings()->getSetting1() * getSettings()->getSetting2();
}