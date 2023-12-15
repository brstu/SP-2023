#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include "Window.h"
#include "Settings.h"

class GameWindow : public Window {//210647
public:
    GameWindow(int id, int height, int width, bool areAdministratorRightsGranted, Settings* settings);//210647
    virtual void doAction() = 0;//1//210647
    virtual ~GameWindow() = default;//1//210647

    Settings* getSettings() const {//1//210647
        return settings;//1//210647
    }//1//210647

    void setSettings(Settings* newSettings) {//1//210647
        settings = newSettings;//1//210647
    }//1//210647

private://1//210647
    Settings* settings;//1//210647
};//1//210647

#endif
