#include "FolderWindow.h"
#include "WFolder.h"
#include "WFile.h"
#include <iostream>
#include <vector>
#include <memory>

int main() {
    Folder folder1("Folder1", 200);
    Folder folder2("Folder2", 300);
    File file1("File1.txt", 50);
    File file2("File2.txt", 100);

    std::vector<FolderObject*> files;
    files.push_back(&folder1);
    files.push_back(&folder2);
    files.push_back(&file1);
    files.push_back(&file2);

    FolderWindow folderWindow(1, 800, 600, true);
    folderWindow.loadFiles(files);

    std::cout << "Initial Memory Needed: " << folderWindow.getMemoryNeeded() << " MB" << std::endl;

    for (int i = 0; i < files.size(); i++) {
        if (dynamic_cast<Folder*>(files[i]) != nullptr) {
            std::cout << "Folder " << i << ": " << dynamic_cast<Folder*>(files[i])->getName() << std::endl;
        }
        else if (dynamic_cast<File*>(files[i]) != nullptr) {
            std::cout << "File " << i << ": " << dynamic_cast<File*>(files[i])->getName() << std::endl;
        }
    }

    folderWindow.navigateForward();
    std::cout << "Memory Needed After Navigating Forward: " << folderWindow.getMemoryNeeded() << " MB" << std::endl;

    for (int i = 0; i < files.size(); i++) {
        if (dynamic_cast<Folder*>(files[i]) != nullptr) {
            std::cout << "Folder " << i << ": " << dynamic_cast<Folder*>(files[i])->getName() << std::endl;
        }
        else if (dynamic_cast<File*>(files[i]) != nullptr) {
            std::cout << "File " << i << ": " << dynamic_cast<File*>(files[i])->getName() << std::endl;
        }
    }

    folderWindow.navigateBackward();
    std::cout << "Memory Needed After Navigating Backward: " << folderWindow.getMemoryNeeded() << " MB" << std::endl;

    for (int i = 0; i < files.size(); i++) {
        if (dynamic_cast<Folder*>(files[i]) != nullptr) {
            std::cout << "Folder " << i << ": " << dynamic_cast<Folder*>(files[i])->getName() << std::endl;
        }
        else if (dynamic_cast<File*>(files[i]) != nullptr) {
            std::cout << "File " << i << ": " << dynamic_cast<File*>(files[i])->getName() << std::endl;
        }
    }

    folderWindow.openFolder(0);
    std::cout << "Memory Needed After Opening Folder 0: " << folderWindow.getMemoryNeeded() << " MB" << std::endl;

    for (int i = 0; i < files.size(); i++) {
        if (dynamic_cast<Folder*>(files[i]) != nullptr) {
            std::cout << "Folder " << i << ": " << dynamic_cast<Folder*>(files[i])->getName() << std::endl;
        }
        else if (dynamic_cast<File*>(files[i]) != nullptr) {
            std::cout << "File " << i << ": " << dynamic_cast<File*>(files[i])->getName() << std::endl;
        }
    }

    folderWindow.openFolder(2); // Trying to open a file, which should not change memory
    std::cout << "Memory Needed After Trying to Open a File: " << folderWindow.getMemoryNeeded() << " MB" << std::endl;

    for (int i = 0; i < files.size(); i++) {
        if (dynamic_cast<Folder*>(files[i]) != nullptr) {
            std::cout << "Folder " << i << ": " << dynamic_cast<Folder*>(files[i])->getName() << std::endl;
        }
        else if (dynamic_cast<File*>(files[i]) != nullptr) {
            std::cout << "File " << i << ": " << dynamic_cast<File*>(files[i])->getName() << std::endl;
        }
    }

    return 0;
}

