#pragma once
#ifndef FOLDERH
#define FOLDERH
#include <string>

class folder
{
public:
	std::string name;
	std::string parent;
	folder(std::string const& _name, std::string const& _parent);
};

#endif