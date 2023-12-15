#include "Window.h"

Window::Window(int id, int height, int width, bool areAdministratorRightsGranted)//1
    : id(id), height(height), width(width), areAdministratorRightsGranted(areAdministratorRightsGranted) {//1
}

void Window::doWork() {//1
    memoryNeeded += 10;//1
}

void Window::showOrHide() {//1
    isShown = false;//1
}