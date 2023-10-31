// Lab4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include "BrowserWindow.h"
#include "iostream"
#include <string>
using namespace std;


int main() {
    Window window(1, 800, 600, true);
    BrowserWindow browser(1, 800, 600, true);
    bool exit = false;
    while (!exit) {


        cout << "1)Show Window\n2)Hide Window\n3)Add Tab\n4)Close Tab\n5)Switch Tab\n6)Search History\n7)Change User\n";
        int option;
        cin >> option;

        switch (option) {
        case 1:
            browser.showOrHide(true);
            break;

        case 2:

            browser.showOrHide(false);


            break;

        case 3:
            browser.addTab();
            break;

        case 4:
            browser.printAllTabs();
            browser.closeTab();
            break;

        case 5:
            browser.switchTab();
            break;

        case 6:
            browser.printAllTabs();
            browser.searchHistory();
            break;



        case 7:
            browser.printAllTabs();
            browser.changeUser();
            break;


        default:
            exit = true;
            break;


        }
    }

    

    return 0;
}