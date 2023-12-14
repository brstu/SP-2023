#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include "Window.h"
#include "Settings.h"

class GameWindow : public Window {//1
public:
    GameWindow(int id, int height, int width, bool areAdministratorRightsGranted, Settings* settings);//1
    virtual void doAction() = 0;//1
    virtual ~GameWindow() = default;//1

    Settings* getSettings() const {//1
        return settings;//1
    }//1

    void setSettings(Settings* newSettings) {//1
        settings = newSettings;//1
    }//1

private://1
    Settings* settings;//1
};//1

#endif
