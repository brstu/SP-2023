#ifndef ROCK_PAPER_SCISSORS_GAME_WINDOW_H
#define ROCK_PAPER_SCISSORS_GAME_WINDOW_H

#include "GameWindow.h"
#include "Settings.h"

class RockPaperScissorsGameWindow : public GameWindow {//1
public://1
    RockPaperScissorsGameWindow(int id, int height, int width, bool areAdministratorRightsGranted, Settings* settings);//1
    void doAction() override;//1

private:
    int randomChoicePlayer2;//1

    int calculateMemoryNeeded() const;//1
};

#endif