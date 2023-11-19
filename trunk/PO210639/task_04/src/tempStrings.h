#pragma once
#ifndef TEMPSTRINGS_H
#define TEMPSTRINGS_H

#include <vector>
#include "folder.h"

class tempStrings
{
public:
	std::vector<folder> folders;
	std::string currentDisk = "C:";
	std::string currentPath = currentDisk;
	std::string newFolderName = "";
	std::string cdPath = "";
};

#endif
