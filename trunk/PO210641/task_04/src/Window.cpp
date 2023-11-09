#include "Window.h"

Window::Window(int id, int height, int width, bool areAdministratorRightsGranted)
    : id(id), height(height), width(width), memoryNeeded(0), areAdministratorRightsGranted(areAdministratorRightsGranted), isShown(false) {
}

void Window::doWork() {
    memoryNeeded += 10;
}

void Window::showOrHide() {
    isShown = false;
}