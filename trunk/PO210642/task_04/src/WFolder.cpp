#include "WFolder.h"
#include <string>

Folder::Folder(const std::string& name, int size) : name(name), size(size) {
}

int Folder::getMemoryNeeded() const {
    return size;
}

const std::string& Folder::getName() const {
    return name;
}