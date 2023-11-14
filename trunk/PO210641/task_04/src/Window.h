#ifndef WINDOW_H
#define WINDOW_H

class Window {
public:
    Window(int id, int height, int width, bool areAdministratorRightsGranted);
    Window() = default;
    void doWork();
    void showOrHide();

private:
    int id = 0;
    int height = 0;
    int width = 0;
    int memoryNeeded = 0;
    bool areAdministratorRightsGranted = false;
    bool isShown = false;
};

#endif // WINDOW_H