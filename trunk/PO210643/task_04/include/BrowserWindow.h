#ifndef BROWSERWINDOW_H
#define BROWSERWINDOW_H

#include <string>
#include <vector>
#include "Window.h"
#include "Tab.h"

class BrowserWindow : public Window {
public:
    BrowserWindow(int id, int height, int width, bool areAdminRightsGranted);
    void addTab();
    void switchTab();
    void closeTab();
    void printAllTabs();
    void searchHistory();
    void changeUser();

private:
    std::vector<Tab> tabs;
    std::string username;
    int currentIndex;
};

#endif