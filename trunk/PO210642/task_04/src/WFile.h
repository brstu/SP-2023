#ifndef FILE_H
#define FILE_H

#include "FolderObject.h"
#include <string>

class File : public FolderObject {
public:
    File(const std::string& name, int size);
    int getMemoryNeeded() const override;
    const std::string& getName() const;

private:
    std::string name;
    int size;
};

#endif
