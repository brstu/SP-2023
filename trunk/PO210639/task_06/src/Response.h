#pragma once
#ifndef RESPONSE_H
#define RESPONSE_H

#include "Data.h"
#include <vector>
#include <string>
#include "Person.h"
#include <memory>

class Response
{
private:
	std::vector<Data*> data;
	void printDataWithCondition(std::vector<std::string>const &whereFields, std::vector<std::string>const &values, std::vector<std::string> const &fields, Data* record) const;
	void printSelectedFields(std::vector<std::string>const &fields) const;
	void insertSelectedFields(std::vector<std::string> substrings, int tempId, std::shared_ptr<Person> person) const;
	void deleteValuesFromVector(std::vector<std::string>const &fields, std::vector<std::string>const &values, Person* tempPerson);
	void updateValuesFromVector(std::vector<std::string>const& fields, std::vector<std::string> const& changedFields, std::vector<std::string> const& newValues, std::vector<std::string>const& values, class Person* tempPerson);
	void setValue(std::vector<std::string>const& changedFields, std::vector<std::string>const& newValues, class Person* tempPerson, int i);
public:
	
	void selectData(std::string request);
	void insertData(std::string request);
	void deleteData(std::string request);
	void updateData(std::string request);
	
};

#endif