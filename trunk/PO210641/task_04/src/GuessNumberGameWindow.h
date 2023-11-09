#ifndef GUESS_NUMBER_GAME_WINDOW_H
#define GUESS_NUMBER_GAME_WINDOW_H

#include "GameWindow.h"
#include "Settings.h"

class GuessNumberGameWindow : public GameWindow {
public:
    GuessNumberGameWindow(int id, int height, int width, bool areAdministratorRightsGranted, Settings* settings);
    void doAction() override;

private:
    int targetNumber;
    int calculateMemoryNeeded() const;
};

#endif
