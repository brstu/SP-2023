#ifndef ROCK_PAPER_SCISSORS_GAME_WINDOW_H
#define ROCK_PAPER_SCISSORS_GAME_WINDOW_H

#include "GameWindow.h"
#include "Settings.h"

class RockPaperScissorsGameWindow : public GameWindow {
public:
    RockPaperScissorsGameWindow(int id, int height, int width, bool areAdministratorRightsGranted, Settings* settings);
    void doAction() override;

private:
    int randomChoicePlayer2;

    int calculateMemoryNeeded() const;
};

#endif