#ifndef FOLDER_H
#define FOLDER_H

#include "FolderObject.h"
#include <vector>
#include <string>

class Folder : public FolderObject {
public:
    Folder(const std::string& name, int size);
    int getMemoryNeeded() const override;
    const std::string& getName() const;

private:
    std::string name;
    int size;
};

#endif
