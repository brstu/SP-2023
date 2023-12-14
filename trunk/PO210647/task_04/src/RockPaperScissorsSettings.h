#ifndef ROCK_PAPER_SCISSORS_SETTINGS_H
#define ROCK_PAPER_SCISSORS_SETTINGS_H

#include "Settings.h"//1

class RockPaperScissorsSettings : public Settings {//1
public:
    RockPaperScissorsSettings();//1
    ~RockPaperScissorsSettings() override = default;//1

    // �������� �������� ��� ���� "������-�������-������"//1
};

#endif