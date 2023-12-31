#include "Response.h"
#include <iostream>
#include "Person.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <format>

using namespace std;

void Response::printDataWithCondition(vector<string>const& whereFields, vector<string>const& values, vector<string> const& fields, Data* record) const
{
	if (whereFields[0] == "id") {
		Person tempPerson = *static_cast<Person*>(record);
		int tempId;
		std::istringstream(values[0]) >> tempId;
		if (tempPerson.id == tempId) {
			tempPerson.print(fields);
			cout << "-----------------------------------------------------------------------------------------------" << endl;
		}
	}
	if (whereFields[0] == "surname") {
		Person tempPerson = *static_cast<Person*>(record);
		string tempSurname;
		tempSurname = values[0];
		if (tempPerson.surname == tempSurname) {
			tempPerson.print(fields);
			cout << "-----------------------------------------------------------------------------------------------" << endl;
		}
	}
	if (whereFields[0] == "name") {
		Person tempPerson = *static_cast<Person*>(record);
		string tempName;
		tempName = values[0];
		if (tempPerson.name == tempName) {
			tempPerson.print(fields);
			cout << "-----------------------------------------------------------------------------------------------" << endl;
		}
	}
	if (whereFields[0] == "age") {
		Person tempPerson = *static_cast<Person*>(record);
		int tempAge;
		std::istringstream(values[0]) >> tempAge;
		if (tempPerson.age == tempAge) {
			tempPerson.print(fields);
			cout << "-----------------------------------------------------------------------------------------------" << endl;
		}
	}
}

void Response::printSelectedFields(vector<string>const& fields) const
{
	if (fields.empty()) {
		cout << "wrong request!" << endl;
		return;
	}

	int countOf_ = 0;
	for (int i = 0; i < fields.size(); i++) {
		if (i != 0) {
			countOf_ = countOf_ + static_cast<int>(fields[i].size());
		}
		countOf_ += 20;
	}

	string outputStr = "";
	string rowsDelim = "";

	for (int i = 0; i <= countOf_; i++) {
		outputStr += '_';
		rowsDelim += '-';
	}
	cout << outputStr << endl;
	cout << "|";
	for (int i = 0; i < fields.size(); i++) {
		if (i == 0) {
			cout << std::format("{: ^10}", fields[i]) << std::format("{: >10}", '|');
		}
		else {
			cout << std::format("{: ^13}", fields[i]) << std::format("{: >10}", '|');
		}
	}
	cout << endl << rowsDelim << endl;

	for (Data* var : data) {
		auto tempPerson = make_shared<Person>();
		tempPerson.reset(static_cast<Person*>(var));
		tempPerson->print(fields);
		cout << rowsDelim << endl;
	}

}

void Response::insertSelectedFields(std::vector<std::string>substrings, int tempId, std::shared_ptr<Person> person) const
{
	vector<string> fields;
	string temp;
	vector<string>::iterator itOfInto;
	itOfInto = std::ranges::find(substrings.begin(), substrings.end(), "INTO");
	vector<string>::iterator it = substrings.begin() + 1;
	while (it != itOfInto) {
		temp = *it;
		if (temp[temp.size() - 1] == ',') {
			temp.erase(temp.size() - 1);
		}
		fields.push_back(temp);
		it += 1;
	}

	vector<string> values;
	vector<string>::iterator itOfValues;
	itOfValues = std::ranges::find(substrings.begin(), substrings.end(), "VALUES");
	it = itOfValues + 1;
	while (it != substrings.end()) {

		temp = *it;
		if (temp[temp.size() - 1] == ',') {

			temp.erase(temp.size() - 1);
		}
		if (temp[0] == '(') {

			temp.erase(0, 1);
		}
		if (temp[0] == '`') {

			temp.erase(0, 1);
		}
		if (temp[temp.size() - 1] == '`') {
			temp.erase(temp.size() - 1);
		}
		values.push_back(temp);
		it += 1;
	}
	person->id = tempId + 1;
	for (int i = 0; i < fields.size(); i++) {
		if (fields[i] == "name") {
			person->name = values[i];
			continue;
		}
		if (fields[i] == "surname") {
			person->surname = values[i];
			continue;
		}
		if (fields[i] == "age") {
			std::istringstream(values[i]) >> person->age;
			continue;
		}
	}

	ofstream out("person.txt", ios::app);
	if (out.is_open()) {
		out << endl << person->id << endl;
		out << person->surname << endl;
		out << person->name << endl;
		out << person->age;
	}
	out.close();
}

void Response::deleteValuesFromVector(std::vector<std::string> const& fields, std::vector<std::string> const& values, std::vector<std::shared_ptr<Person>> sharedPtrs)
{
	if (fields[0] == "id") {
		for (int i = 0; i < data.size(); i++) {
			auto tempPerson = make_shared<Person>();
			*tempPerson = *static_cast<Person*>(data[i]);
			sharedPtrs.push_back(tempPerson);
			int tempId;
			std::istringstream(values[0]) >> tempId;
			if (tempPerson->id == tempId) {
				auto deleteItem = data.begin() + i;
				data.erase(deleteItem);
			}

		}
	}
	else if (fields[0] == "surname") {
		for (int i = 0; i < data.size(); i++) {
			auto tempPerson = make_shared<Person>();
			*tempPerson = *static_cast<Person*>(data[i]);
			sharedPtrs.push_back(tempPerson);
			string tempSurname = values[0];
			if (tempPerson->surname == tempSurname) {
				auto deleteItem = data.begin() + i;
				data.erase(deleteItem);
			}
		}
	}
	else if (fields[0] == "name") {
		for (int i = 0; i < data.size(); i++) {
			auto tempPerson = make_shared<Person>();
			*tempPerson = *static_cast<Person*>(data[i]);
			sharedPtrs.push_back(tempPerson);
			string tempName = values[0];
			if (tempPerson->name == tempName) {
				auto deleteItem = data.begin() + i;
				data.erase(deleteItem);
			}
		}
	}
	else if (fields[0] == "age") {
		for (int i = 0; i < data.size(); i++) {
			auto tempPerson = make_shared<Person>();
			*tempPerson = *static_cast<Person*>(data[i]);
			sharedPtrs.push_back(tempPerson);
			int tempAge;
			std::istringstream(values[0]) >> tempAge;
			if (tempPerson->age == tempAge) {
				auto deleteItem = data.begin() + i;
				data.erase(deleteItem);
			}
		}
	}
}

void Response::updateValuesFromVector(std::vector<std::string>const& fields, std::vector<std::string> const& changedFields, std::vector<std::string> const& newValues, std::vector<std::string>const& values, std::vector<std::shared_ptr<Person>> &sharedPtrs)
{
	if (fields[0] == "id") {
		for (int i = 0; i < data.size(); i++) {
			auto tempPerson = make_shared<Person>();
			
			*tempPerson = *static_cast<Person*>(data[i]);
			
			sharedPtrs.push_back(tempPerson);
			int tempId;
			std::istringstream(values[0]) >> tempId;
			
			if (tempPerson->id == tempId) {
				setValue(changedFields, newValues, tempPerson, i);
			}
		}
	}
	else if (fields[0] == "surname") {
		for (int i = 0; i < data.size(); i++) {
			auto tempPerson = make_shared<Person>();
			*tempPerson = *static_cast<Person*>(data[i]);
			sharedPtrs.push_back(tempPerson);
			string tempSurname = values[0];
			if (tempPerson->surname == tempSurname) {
				setValue(changedFields, newValues, tempPerson, i);
			}
		}
	}
	else if (fields[0] == "name") {
		for (int i = 0; i < data.size(); i++) {
			auto tempPerson = make_shared<Person>();
			*tempPerson = *static_cast<Person*>(data[i]);
			sharedPtrs.push_back(tempPerson);
			string tempName = values[0];
			if (tempPerson->name == tempName) {
				setValue(changedFields, newValues, tempPerson, i);
				
			}
		}
	}
	else if (fields[0] == "age") {
		for (int i = 0; i < data.size(); i++) {
			auto tempPerson = make_shared<Person>();
			*tempPerson = *static_cast<Person*>(data[i]);
			sharedPtrs.push_back(tempPerson);
			int tempAge;
			std::istringstream(values[0]) >> tempAge;
			if (tempPerson->age == tempAge) {
				setValue(changedFields, newValues, tempPerson, i);
			}
		}
	}
}

void Response::setValue(std::vector<std::string>const& changedFields, std::vector<std::string>const& newValues, std::shared_ptr<Person> tempPerson, int i)
{
	if (changedFields[0] == "surname") {
		tempPerson->surname = newValues[0];
	}
	if (changedFields[0] == "name") {
		tempPerson->name = newValues[0];
	}
	if (changedFields[0] == "age") {
		std::istringstream(newValues[0]) >> tempPerson->age;
	}
	data[i] = tempPerson.get();
}

void Response::getRecords(std::string temp, std::vector<std::shared_ptr<Person>> &ptrs)
{
	ifstream in("person.txt", ios::in);
	if (in.is_open()) {
		while (getline(in, temp, '\n')) {
			auto person = make_shared<Person>();
			ptrs.push_back(person);
			std::istringstream(temp) >> person->id;
			getline(in, temp, '\n');
			person->surname = temp;
			getline(in, temp, '\n');
			person->name = temp;
			getline(in, temp, '\n');
			std::istringstream(temp) >> person->age;

			data.push_back(static_cast<Data*>(person.get()));
		}
	}
	in.close();
}

void Response::getRecordsAndLastId(std::string temp, std::vector<std::shared_ptr<Person>>& ptrs, int &tempId)
{
	ifstream in("person.txt", ios::in);
	if (in.is_open()) {
		while (getline(in, temp, '\n')) {
			auto person = make_shared<Person>();
			ptrs.push_back(person);
			std::istringstream(temp) >> person->id;
			tempId = person->id;
			getline(in, temp, '\n');
			person->surname = temp;
			getline(in, temp, '\n');
			person->name = temp;
			getline(in, temp, '\n');
			std::istringstream(temp) >> person->age;

			data.push_back(static_cast<Data*>(person.get()));
		}
	}
	in.close();
}

void Response::getSubstrings(std::vector<std::string> &substrings, std::string request) const
{
	string delim = " ";
	int pos = 0;
	while (pos != std::string::npos) {
		pos = static_cast<int>(request.find(delim));
		substrings.push_back(request.substr(0, pos));
		request.erase(0, pos + delim.length());
	}
	substrings.push_back(request.substr(0, request.size()));
}

void Response::getSubstringsForDeleteAndUpdate(std::vector<std::string>& substrings, std::string request) const
{
	string delim = " ";
	int pos = 0;
	while (pos != request.size()) {
		pos = static_cast<int>(request.find(delim));
		substrings.push_back(request.substr(0, pos));
		request.erase(0, pos + delim.size());
		if (request.size() == 1) {
			substrings.push_back(request);
			break;
		}

	}
}

void Response::printRecords(std::vector<std::shared_ptr<Person>> sharedPtrs)
{
	ofstream out("person.txt", ios::out);
	if (out.is_open()) {
		for (int i = 0; i < data.size(); i++) {
			auto tempPerson = make_shared<Person>();
			*tempPerson = *static_cast<Person*>(data[i]);
			sharedPtrs.push_back(tempPerson);
			out << tempPerson->id << endl;
			out << tempPerson->surname << endl;
			out << tempPerson->name << endl;
			if (i == data.size() - 1) {
				out << tempPerson->age;
			}
			else {
				out << tempPerson->age << endl;
			}
		}
	}
	out.close();
}

void Response::selectData(string const &request)
{
	std::vector<std::shared_ptr<Person>> ptrs;
	data.clear();
	string temp;

	getRecords(temp, ptrs);
	
	vector<string> substrings;

	getSubstrings(substrings, request);

	vector<string> whereFields;
	vector<string> values;
	if (auto it = std::ranges::find(substrings.begin(), substrings.end(), "WHERE"); it != substrings.end()) {
		it += 1;
		while (it != substrings.end()) {
			whereFields.push_back(*it);
			it += 2;
			values.push_back(*it);
			it += 1;
		}
	}
	auto it = substrings.begin() + 1;
	if (substrings[1] == "*") {
		vector<string> fields;
		fields.emplace_back("id");
		fields.emplace_back("surname");
		fields.emplace_back("name");
		fields.emplace_back("age");
		cout << "_______________________________________________________________________________________________" << endl;//94+'/0'
		cout << "|" << std::format("{: ^10}", "id") << std::format("{: >10}", '|') << std::format("{: ^17}", "surname") << std::format("{: >10}", '|') << std::format("{: ^14}", "name") << std::format("{: >10}", '|') << std::format("{: ^13}", "age") << std::format("{: >10}", '|') << endl;
		cout << "-----------------------------------------------------------------------------------------------" << endl;

		for (Data* var : data) {
			if (!whereFields.empty()) {
				printDataWithCondition(whereFields, values, fields, var);
			}
			else {
				Person person = *static_cast<Person*>(var);
				person.print(fields);
				cout << "-----------------------------------------------------------------------------------------------" << endl;
			}
		}
	}
	else {

		auto posOfFrom = std::ranges::find(substrings.begin(), substrings.end(), "FROM");
		vector<string> fields;

		while (it != posOfFrom) {
			temp = *it;
			if (temp[temp.size() - 1] == ',') {
				temp.erase(temp.size() - 1);
			}
			fields.push_back(temp);
			it += 1;
		}

		printSelectedFields(fields);
	}
	ptrs.clear();
}

void Response::insertData(string const &request)
{
	std::vector<std::shared_ptr<Person>> ptrs;

	vector<string> substrings;
	getSubstrings(substrings, request);

	string temp;
	int tempId=0;

	getRecordsAndLastId(temp, ptrs, tempId);

	if (substrings[1] == "INTO") {
		auto person = make_shared<Person>();
		ptrs.push_back(person);
		person->id = tempId + 1;
		substrings[4].erase(0, 2);
		substrings[4].erase(substrings[4].size() - 2, 2);
		person->surname = substrings[4];
		substrings[5].erase(0, 1);
		substrings[5].erase(substrings[5].size() - 2, 2);
		person->name = substrings[5];
		substrings[6].erase(0, 1);
		substrings[6].erase(substrings[6].size() - 1);
		std::istringstream(substrings[6]) >> person->age;

		if (person->id == 1) {
			ofstream out("person.txt", ios::out);
			if (out.is_open()) {
				out << person->id << endl;
				out << person->surname << endl;
				out << person->name << endl;
				out << person->age;
			}
			out.close();
		}
		else {
			ofstream out("person.txt", ios::app);
			if (out.is_open()) {
				out << endl << person->id << endl;
				out << person->surname << endl;
				out << person->name << endl;
				out << person->age;
			}
			out.close();
		}

	}
	else {
		auto person = make_shared<Person>();
		ptrs.push_back(person);
		insertSelectedFields(substrings, tempId, person);
	}
	ptrs.clear();
}

void Response::deleteData(string const& request)
{
	std::vector<std::shared_ptr<Person>> ptrs;
	data.clear();
	string temp;

	getRecords(temp, ptrs);

	vector<string> substrings;

	getSubstringsForDeleteAndUpdate(substrings, request);

	vector<string> fields;
	vector<string> values;

	if (auto it = std::ranges::find(substrings.begin(), substrings.end(), "WHERE"); it != substrings.end()) {
		it += 1;
		while (it != substrings.end()) {
			fields.push_back(*it);
			it += 2;
			values.push_back(*it);
			it += 1;
		}
	}
	else {
		cout << "wrong request!" << endl;
		return;
	}

	vector<shared_ptr<Person>> sharedPtrs;

	deleteValuesFromVector(fields, values, sharedPtrs);

	printRecords(sharedPtrs);

	ptrs.clear();
}

void Response::updateData(string const& request)
{
	std::vector<std::shared_ptr<Person>> ptrs;
	data.clear();
	string temp;
	getRecords(temp, ptrs);

	vector<string> substrings;
	getSubstringsForDeleteAndUpdate(substrings, request);

	vector<string> changedFields;
	vector<string> newValues;
	vector<string> fields;
	vector<string> values;

	if (auto it = std::ranges::find(substrings.begin(), substrings.end(), "SET"); it != substrings.end()) {
		it +=1;
		while (*it != "WHERE") {
			changedFields.push_back(*it);
			it += 2;
			newValues.push_back(*it);
			it +=1;
		}
		it +=1;
		while (it != substrings.end()) {
			fields.push_back(*it);
			it += 2;
			values.push_back(*it);
			it++;
		}
	}
	else {
		cout << "wrong request!" << endl;
		return;
	}

	vector<shared_ptr<Person>> sharedPtrs;

	updateValuesFromVector(fields, changedFields, newValues, values, sharedPtrs);
	printRecords(sharedPtrs);
	ptrs.clear();
	sharedPtrs.clear();

}

