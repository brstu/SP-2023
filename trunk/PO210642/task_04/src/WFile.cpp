#include "WFile.h"
#include <string>

File::File(const std::string& name, int size) : name(name), size(size) {
}

int File::getMemoryNeeded() const {
    return size;
}

const std::string& File::getName() const {
    return name;
}