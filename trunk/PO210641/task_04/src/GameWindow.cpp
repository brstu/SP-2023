#include "GameWindow.h"

GameWindow::GameWindow(int id, int height, int width, bool areAdministratorRightsGranted, Settings* settings)
    : Window(id, height, width, areAdministratorRightsGranted), settings(settings) {
}