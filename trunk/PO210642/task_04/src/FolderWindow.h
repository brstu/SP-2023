#ifndef FOLDER_WINDOW_H
#define FOLDER_WINDOW_H

#include "Window.h"
#include "FolderObject.h"
#include <vector>

class FolderWindow : public Window {
public:
    FolderWindow(int id, int height, int width, bool areAdminRightsGranted);
    void loadFiles(const std::vector<FolderObject*>& files);
    void navigateForward();
    void navigateBackward();
    void openFolder(int index);
    int getMemoryNeeded() const;

private:
    std::vector<FolderObject*> files;
    int currentIndex;
};

#endif
