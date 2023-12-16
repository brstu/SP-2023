#pragma once
#ifndef DATA_H
#define DATA_H

#include <vector>
#include <string>

class Data
{
public:
	void virtual print(std::vector<std::string> fields) = 0;
	virtual ~Data()=default;
};

#endif