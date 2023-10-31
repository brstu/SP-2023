#include "BrowserWindow.h"
#include "Tab.h"
#include "iostream"

void print(const std::string& condition) {
    std::cout << "Enter  " << condition << ": ";


}

BrowserWindow::BrowserWindow(int id, int height, int width, [[maybe_unused]] bool areAdminRightsGranted)
    : Window(id, height, width, areAdminRightsGranted)
{
}

void BrowserWindow::addTab() {
    if (!isShown) {
        std::cout << "Open Window first!" << std::endl;
    }
    else {
        std::string url;
        print("url");
        std::cin >> url;


        Tab newTab(url);
        tabs.push_back(newTab);
        memoryNeeded = tabs.size();
        std::cout << "Added tab: " << url << std::endl;

    }

}

void BrowserWindow::switchTab() const {
    if (!isShown) {
        std::cout << "Open Window first!" << std::endl;
    }
    else {
        int index;
        print("number of Tab");
        std::cin >> index;
        if (index - 1 >= 0 && index - 1 < tabs.size()) {
            std::cout << "Switched to tab " << index << std::endl;
        }
    }
}

void BrowserWindow::closeTab() {
    if (!isShown) {
        std::cout << "Open Window first!" << std::endl;
    }
    else {
        int index;
        print("number of Tab");
        std::cin >> index;
        if (index - 1 >= 0 && index - 1 < tabs.size()) {
            tabs.erase(tabs.begin() + index - 1);
            memoryNeeded = tabs.size();
            std::cout << "Tab " << index << " closed" << std::endl;

        }
        std::cout << "Opened tabs:";
        for (const Tab& tab : tabs) {
            std::cout << tab.getUrl() << std::endl;
        }
    }

}

void BrowserWindow::printAllTabs() {

    for (size_t i = 0; i < tabs.size(); i++) {
        std::cout << "Tab " << i + 1 << " URL: " << tabs[i].getUrl() << std::endl;

    }
}
void BrowserWindow::searchHistory() {
    if (!isShown) {
        std::cout << "Open Window first!" << std::endl;
    }
    else {
        std::string keyword;
        bool found = false;
        print("keyword");
        std::cin >> keyword;
        for (size_t i = 0; i < tabs.size(); i++) {
            std::string url = tabs[i].getUrl();


            if (url.find(keyword, 0) != std::string::npos) {
                std::cout << url << " is found under number:" << i + 1 << std::endl;
                found = true;
            }


        }
        if (!found)std::cout << "No such tab" << std::endl;
    }



}

void BrowserWindow::changeUser() {
    if (!isShown) {
        std::cout << "Open Window first!" << std::endl;
    }
    else {
        std::string newUser;
        print("new user");
        std::cin >> newUser;
        username = newUser;
        std::cout << "User switched to: " << newUser << std::endl;
        tabs.clear();
    }
}

