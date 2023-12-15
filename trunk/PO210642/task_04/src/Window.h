#ifndef WINDOW_H
#define WINDOW_H

class Window {
public:
    Window(int id, int height, int width, bool areAdminRightsGranted);
    void doWork();
    void showOrHide(bool value);

protected:
    int id;
    int height;
    int width;
    int memoryNeeded;
    bool areAdminRightsGranted;
    bool isShown;
};

#endif
