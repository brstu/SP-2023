#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include "Window.h"
#include "Settings.h"

class GameWindow : public Window {
public:
    GameWindow(int id, int height, int width, bool areAdministratorRightsGranted, Settings* settings);
    virtual void doAction() = 0;
    virtual ~GameWindow() = default;

    Settings* getSettings() const {
        return settings;
    }

    void setSettings(Settings* newSettings) {
        settings = newSettings;
    }

private:
    Settings* settings;
};

#endif
