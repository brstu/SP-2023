#pragma once
#ifndef PERSON_H
#define PERSON_H

#include "Data.h"
#include <string>
#include <vector>

class Person : public Data
{
public:
	int id= NULL;
	std::string surname = "null";
	std::string name = "null";
	int age = NULL;
	void print(std::vector<std::string> fields) override;
};

#endif