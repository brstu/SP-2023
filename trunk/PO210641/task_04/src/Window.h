#ifndef WINDOW_H
#define WINDOW_H

class Window {
public:
    Window(int id, int height, int width, bool areAdministratorRightsGranted);
    void doWork();
    void showOrHide();

private:
    int id;
    int height;
    int width;
    int memoryNeeded = 0;
    bool areAdministratorRightsGranted;
    bool isShown = false;
};

#endif // WINDOW_H
