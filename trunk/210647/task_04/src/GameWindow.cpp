#include "GameWindow.h"

GameWindow::GameWindow(int id, int height, int width, bool areAdministratorRightsGranted, Settings* settings)//210647
    : Window(id, height, width, areAdministratorRightsGranted), settings(settings) {//210647
}