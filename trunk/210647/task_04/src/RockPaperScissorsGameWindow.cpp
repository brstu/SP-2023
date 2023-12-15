#include "RockPaperScissorsGameWindow.h"
#include <iostream>
#include <ctime>
#include <random>

using namespace std;

RockPaperScissorsGameWindow::RockPaperScissorsGameWindow(int id, int height, int width, bool areAdministratorRightsGranted, Settings* settings)//1//210647
    : GameWindow(id, height, width, areAdministratorRightsGranted, settings) {//1//210647
    std::random_device rd;//1//210647
    std::uniform_int_distribution distribution(0, 2);//1//210647
    randomChoicePlayer2 = distribution(rd);//1//210647
}

void RockPaperScissorsGameWindow::doAction() {//1//210647
    doWork();//1//210647
    int memoryNeeded = calculateMemoryNeeded();//1//210647
    cout << "Memory Needed: " << memoryNeeded << " MB" << endl;//1//210647

    int player1Choice;//1//210647
    cout << "Player 1, enter your choice (0 - Rock, 1 - Scissors, 2 - Paper): ";//1//210647
    cin >> player1Choice;//1//210647


    string choicePlayer1;//1//210647
    string choicePlayer2;//1//210647

    if (player1Choice == 0) {//1//210647
        choicePlayer1 = "Rock";//1//210647
    }//1//210647
    else if (player1Choice == 1) {//1//210647
        choicePlayer1 = "Scissors";//1//210647
    }//1//210647
    else {//1//210647
        choicePlayer1 = "Paper";//1//210647
    }//1//210647

    if (randomChoicePlayer2 == 0) {//1//210647
        choicePlayer2 = "Rock";//1//210647
    }//1//210647
    else if (randomChoicePlayer2 == 1) {//1//210647
        choicePlayer2 = "Scissors";//1//210647
    }
    else {//1//210647
        choicePlayer2 = "Paper";//1//210647
    }

    cout << "Player 1 chose: " << choicePlayer1 << endl;//1//210647
    cout << "Player 2 chose: " << choicePlayer2 << endl;//1//210647

    if (player1Choice == randomChoicePlayer2) {//1//210647
        cout << "It's a tie!" << endl;//1//210647
    }
    else if ((player1Choice == 0 && randomChoicePlayer2 == 1) ||//1//210647
        (player1Choice == 1 && randomChoicePlayer2 == 2) ||//1//210647
        (player1Choice == 2 && randomChoicePlayer2 == 0)) {//1//210647
        cout << "Player 1 wins!" << endl;//1//210647
    }
    else {//1//210647
        cout << "Player 2 wins!" << endl;//1//210647
    }
}

int RockPaperScissorsGameWindow::calculateMemoryNeeded() const {//1//210647
    return getSettings()->getSetting1() * getSettings()->getSetting2();//1//210647
}