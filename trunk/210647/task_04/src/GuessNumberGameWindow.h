#ifndef GUESS_NUMBER_GAME_WINDOW_H
#define GUESS_NUMBER_GAME_WINDOW_H

#include "GameWindow.h"
#include "Settings.h"

class GuessNumberGameWindow : public GameWindow {//1//210647
public:
    GuessNumberGameWindow(int id, int height, int width, bool areAdministratorRightsGranted, Settings* settings);//1//210647
    void doAction() override;//1//210647

private:
    int targetNumber;//1//210647
    int calculateMemoryNeeded() const;//1//210647
};

#endif
