#include <iostream>
#include <vector>

class Window {
private:
    int id;
    int height;
    int width;
    int memoryNeeded = 0;
    bool areAdministatorRightsGranted;
    bool isShown = false;
public:
    Window(int id, int height, int width, bool areAdministatorRightsGranted)
        : id(id), height(height), width(width), memoryNeeded(memoryNeeded), areAdministatorRightsGranted(areAdministatorRightsGranted), isShown(isShown) {}

    virtual void doWork() {
        memoryNeeded += 1;
    }
    void changeActiveScreen() {
        // Дополнительная логика изменения активного экрана
        std::cout << "Changing active screen" << std::endl;
    }

    void showOrHide() {
        isShown = !isShown;
    }
};


class Shortcut {
private:
    int id;
    int size;
    int xPosition;
    int yPosition;
    std::string path;

public:
    Shortcut(int id, int size, int xPosition, int yPosition, const std::string& path)
        : id(id), size(size), xPosition(xPosition), yPosition(yPosition), path(path) {}

    void move(int newX, int newY) {
        xPosition = newX;
        yPosition = newY;
    }

    void launch() {
        std::cout << "Launching shortcut: " << path << std::endl;
    }
};

class DesktopWindow : public Window {
private:
    std::vector<Shortcut> shortcuts;
    std::string backgroundImagePath;

public:
    DesktopWindow(int id, int height, int width, bool areAdministatorRightsGranted, const std::string& backgroundImagePath)
        : Window(id, height, width, areAdministatorRightsGranted), backgroundImagePath(backgroundImagePath) {}

    void addShortcut(int shortcutId, int size, int xPosition, int yPosition, const std::string& path) {
        Shortcut shortcut(shortcutId, size, xPosition, yPosition, path);
        shortcuts.push_back(shortcut);
        doWork();
    }

    
};

void createNewScreen(std::vector<Window>& windows) {
    DesktopWindow newScreen(1, 1024, 768, true, "background.png");
    newScreen.addShortcut(1, 50, 200, 200, "shortcut1.exe");
    newScreen.addShortcut(2, 50, 300, 300, "shortcut2.exe");
    windows.push_back(newScreen);
}

void changeActiveScreen(std::vector<Window>& windows, int index) {
    if (index >= 0 && index < windows.size()) {
       windows[index].changeActiveScreen();
    } else {
        std::cout << "Invalid screen index" << std::endl;
    }
}

int main() {
    std::vector<Window> windows;

    createNewScreen(windows);

    changeActiveScreen(windows, 0);

    return 0;
}
