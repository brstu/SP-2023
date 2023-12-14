#ifndef WINDOW_H
#define WINDOW_H

class Window {//1
public://1
    Window(int id, int height, int width, bool areAdministratorRightsGranted);//1
    Window() = default;//1
    void doWork();//1
    void showOrHide();//1

private:
    int id = 0;//1
    int height = 0;//1
    int width = 0;//1
    int memoryNeeded = 0;//1
    bool areAdministratorRightsGranted = false;//1
    bool isShown = false;//1
};

#endif // WINDOW_H