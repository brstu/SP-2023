#include "BrowserWindow.h"
#include "Tab.h"
using namespace std;
#include "iostream"

void print(string condition) {
    cout << "Enter  " << condition << ": ";


}

BrowserWindow::BrowserWindow(int id, int height, int width, bool areAdminRightsGranted)
    : Window(id, height, width, areAdminRightsGranted)
{
}

void BrowserWindow::addTab() {
    if (!isShown) {
        cout << "Open Window first!" << endl;
    }
    else {
        string url;
        print("url");
        cin >> url;


        Tab newTab(url);
        tabs.push_back(newTab);
        memoryNeeded = tabs.size();
        cout << "Added tab: " << url << endl;

    }

}

void BrowserWindow::switchTab() {
    if (!isShown) {
        cout << "Open Window first!" << endl;
    }
    else {
        int index;
        print("number of Tab");
        cin >> index;
        if (index - 1 >= 0 && index - 1 < tabs.size()) {
            int previousIndex = currentIndex;
            currentIndex = index - 1;
            cout << "Switched to tab " << index << endl;;
        }
    }
}

void BrowserWindow::closeTab() {
    if (!isShown) {
        cout << "Open Window first!" << endl;
    }
    else {
        int index;
        print("number of Tab");
        cin >> index;
        if (index - 1 >= 0 && index - 1 < tabs.size()) {
            tabs.erase(tabs.begin() + index - 1);
            memoryNeeded = tabs.size();
            cout << "Tab " << index << " closed" << endl;

        }
        cout << "Opened tabs:";
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
        cout << "Open Window first!" << endl;
    }
    else {
        string keyword;
        bool found = false;
        print("keyword");
        cin >> keyword;
        for (size_t i = 0; i < tabs.size(); i++) {
            std::string url = tabs[i].getUrl();


            if (url.find(keyword, 0) != std::string::npos) {
                cout << url << " is found under number:" << i + 1 << endl;
                found = true;
            }


        }
        if (!found) cout << "No such tab" << endl;
    }



}

void BrowserWindow::changeUser() {
    if (!isShown) {
        cout << "Open Window first!" << endl;
    }
    else {
        string newUser;
        print("new user");
        cin >> newUser;
        username = newUser;
        cout << "User switched to: " << newUser << endl;
        tabs.clear();
    }
}

