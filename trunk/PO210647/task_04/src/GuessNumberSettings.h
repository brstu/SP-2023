#ifndef GUESS_NUMBER_SETTINGS_H
#define GUESS_NUMBER_SETTINGS_H

#include "Settings.h"//1

class GuessNumberSettings : public Settings {//1
public:
    GuessNumberSettings();//1
    ~GuessNumberSettings() override = default;//1
};//1

#endif
