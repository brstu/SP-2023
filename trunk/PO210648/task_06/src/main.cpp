#include <windows.h>
#include <iostream>
#include <string>

void ListFiles(const std::string& path) {
    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFile((path + L"\\*").c_str(), &findFileData);
    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            std::cout << findFileData.cFileName << std::endl;
        } while (FindNextFile(hFind, &findFileData) != 0);
        FindClose(hFind);
    }
}

int main() {
    std::string currentPath = L".";
    while (true) {
        std::cout << L"Current directory: " << currentPath << std::endl;
        ListFiles(currentPath);

        std::string input;
        std::cout << L"Enter command (cd <folder>, new <file>, del <file>, q): ";
        std::cin >> input;

        if (input == L"q") {
            break;
        }
        else if (input == L"cd") {
            std::cin >> input;
            currentPath += L"\\" + input;
        }
        else if (input == L"new") {
            std::cin >> input;
            HANDLE newFile = CreateFile((currentPath + L"\\" + input).c_str(), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
            if (newFile != INVALID_HANDLE_VALUE) {
                CloseHandle(newFile);
                std::cout << L"File created successfully" << std::endl;
            }
            else {
                std::cout << L"Failed to create file" << std::endl;
            }
        }
        else if (input == L"del") {
            std::cin >> input;
            if (DeleteFile((currentPath + L"\\" + input).c_str())) {
                std::cout << L"File deleted successfully" << std::endl;
            }
            else {
                std::cout << L"Failed to delete file" << std::endl;
            }
        }
    }
    return 0;
}
