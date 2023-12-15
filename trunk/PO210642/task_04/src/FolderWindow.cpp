#include "FolderWindow.h"
#include "WFolder.h"
#include <iostream>

FolderWindow::FolderWindow(int id, int height, int width, bool areAdminRightsGranted)
    : Window(id, height, width, areAdminRightsGranted), currentIndex(0) {
}

void FolderWindow::loadFiles(const std::vector<FolderObject*>& files) {
    this->files = files;
}

void FolderWindow::navigateForward() {
    if (currentIndex + 1 < files.size()) {
        currentIndex++;
        doWork();
    }
}

void FolderWindow::navigateBackward() {
    if (currentIndex > 0) {
        currentIndex--;
        doWork();
    }
}

void FolderWindow::openFolder(int index) {
    if (index >= 0 && index < files.size()) {
        if (dynamic_cast<Folder*>(files[index]) != nullptr) {
            currentIndex = index;
            doWork();
        }
    }
}

int FolderWindow::getMemoryNeeded() const {
    int totalMemory = memoryNeeded;
    for (const auto& file : files) {
        totalMemory += file->getMemoryNeeded();
    }
    return totalMemory;
}
