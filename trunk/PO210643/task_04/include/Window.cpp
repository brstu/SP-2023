#include "Window.h"
#include "iostream"
using namespace std;
Window::Window(int id, int height, int width, bool areAdminRightsGranted) {
    this->id = id;
    this->height = height;
    this->width = width;
    this->areAdministratorRightsGranted = areAdminRightsGranted;
    memoryNeeded = 0;
    isShown = false;


}


void Window::doWork() {
    memoryNeeded += 100;

}

void Window::showOrHide(bool  value) {
    isShown = value;
    cout << "Window " << id << " is " << (value ? "shown" : "hidden") << std::endl;
}
