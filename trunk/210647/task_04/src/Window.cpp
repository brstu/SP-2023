#include "Window.h"

Window::Window(int id, int height, int width, bool areAdministratorRightsGranted)//1//210647
    : id(id), height(height), width(width), areAdministratorRightsGranted(areAdministratorRightsGranted) {//1//210647
}

void Window::doWork() {//1//210647
    memoryNeeded += 10;//1//210647
}

void Window::showOrHide() {//1//210647
    isShown = false;//1//210647
}