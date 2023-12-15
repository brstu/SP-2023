#include "RockPaperScissorsGameWindow.h"
#include <iostream>
#include <ctime>
#include <random>

using namespace std;

RockPaperScissorsGameWindow::RockPaperScissorsGameWindow(int id, int height, int width, bool areAdministratorRightsGranted, Settings* settings)//1
    : GameWindow(id, height, width, areAdministratorRightsGranted, settings) {//1
    std::random_device rd;//1
    std::uniform_int_distribution distribution(0, 2);//1
    randomChoicePlayer2 = distribution(rd);//1
}

void RockPaperScissorsGameWindow::doAction() {//1
    doWork();//1
    int memoryNeeded = calculateMemoryNeeded();//1
    cout << "Memory Needed: " << memoryNeeded << " MB" << endl;//1

    int player1Choice;//1
    cout << "Player 1, enter your choice (0 - Rock, 1 - Scissors, 2 - Paper): ";//1
    cin >> player1Choice;//1


    string choicePlayer1;//1
    string choicePlayer2;//1

    if (player1Choice == 0) {//1
        choicePlayer1 = "Rock";//1
    }//1
    else if (player1Choice == 1) {//1
        choicePlayer1 = "Scissors";//1
    }//1
    else {//1
        choicePlayer1 = "Paper";//1
    }//1

    if (randomChoicePlayer2 == 0) {//1
        choicePlayer2 = "Rock";//1
    }//1
    else if (randomChoicePlayer2 == 1) {//1
        choicePlayer2 = "Scissors";//1
    }
    else {//1
        choicePlayer2 = "Paper";//1
    }

    cout << "Player 1 chose: " << choicePlayer1 << endl;//1
    cout << "Player 2 chose: " << choicePlayer2 << endl;//1

    if (player1Choice == randomChoicePlayer2) {//1
        cout << "It's a tie!" << endl;//1
    }
    else if ((player1Choice == 0 && randomChoicePlayer2 == 1) ||//1
        (player1Choice == 1 && randomChoicePlayer2 == 2) ||//1
        (player1Choice == 2 && randomChoicePlayer2 == 0)) {//1
        cout << "Player 1 wins!" << endl;//1
    }
    else {//1
        cout << "Player 2 wins!" << endl;//1
    }
}

int RockPaperScissorsGameWindow::calculateMemoryNeeded() const {//1
    return getSettings()->getSetting1() * getSettings()->getSetting2();//1
}