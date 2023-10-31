#include "Window.h"
#include "iostream"
Window::Window(int id, int height, int width, bool areAdminRightsGranted) :id(id), height(height), width(width), areAdminRightsGranted(areAdminRightsGranted){


}


void Window::doWork() {
    memoryNeeded += 100;

}

void Window::showOrHide(bool  value) {
    isShown = value;
    std::cout << "Window " << id << " is " << (value ? "shown" : "hidden") << std::endl;
}
