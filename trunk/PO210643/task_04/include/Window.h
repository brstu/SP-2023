#ifndef WINDOW_H
#define WINDOW_H

class Window {
public:
    Window(int id, int height, int width, bool areAdminRightsGranted);
    void doWork();
    void showOrHide(bool value);

public:
    int id;
    int height;
    int width;
    int memoryNeeded;
    bool areAdministratorRightsGranted;
    bool isShown;
};

#endif