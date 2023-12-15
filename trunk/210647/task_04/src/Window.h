#ifndef WINDOW_H
#define WINDOW_H

class Window {//1//210647
public://1//210647
    Window(int id, int height, int width, bool areAdministratorRightsGranted);//1//210647
    Window() = default;//1//210647
    void doWork();//1//210647
    void showOrHide();//1//210647

private:
    int id = 0;//1//210647
    int height = 0;//1//210647
    int width = 0;//1//210647
    int memoryNeeded = 0;//1//210647
    bool areAdministratorRightsGranted = false;//1//210647
    bool isShown = false;//1//210647
};//210647

#endif // WINDOW_H