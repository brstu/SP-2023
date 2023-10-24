#ifndef WINDOW_H
#define WINDOW_H

class Window {
public:
    Window(int id, int height, int width, bool areAdminRightsGranted
    );
    void doWork();
    void showOrHide(bool value);
    int id;
    int height;
    int width;
    int memoryNeeded=0;
    bool areAdministratorRightsGranted=false;
    bool isShown=false;
};

#endif