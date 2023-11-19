#include "Response.h"
#include <iostream>
#include "Person.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <format>

using namespace std;

void Response::printDataWithCondition(vector<string> whereFields, vector<string> values, vector<string> const &fields, Data* record) const
{
	if (whereFields[0] == "id") {
		Person tempPerson = *(Person*)record;
		int tempId;
		std::istringstream(values[0]) >> tempId;
		if (tempPerson.id == tempId) {
			tempPerson.print(fields);
			cout << "-----------------------------------------------------------------------------------------------" << endl;
		}
	}
	if (whereFields[0] == "surname") {
		Person tempPerson = *(Person*)record;
		string tempSurname;
		tempSurname = values[0];
		if (tempPerson.surname == tempSurname) {
			tempPerson.print(fields);
			cout << "-----------------------------------------------------------------------------------------------" << endl;
		}
	}
	if (whereFields[0] == "name") {
		Person tempPerson = *(Person*)record;
		string tempName;
		tempName = values[0];
		if (tempPerson.name == tempName) {
			tempPerson.print(fields);
			cout << "-----------------------------------------------------------------------------------------------" << endl;
		}
	}
	if (whereFields[0] == "age") {
		Person tempPerson = *(Person*)record;
		int tempAge;
		std::istringstream(values[0]) >> tempAge;
		if (tempPerson.age == tempAge) {
			tempPerson.print(fields);
			cout << "-----------------------------------------------------------------------------------------------" << endl;
		}
	}
}

void Response::printSelectedFields(vector<string> fields) const
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
		tempPerson.reset((Person*)var);
		tempPerson->print(fields);
		cout << rowsDelim << endl;
	}

}

void Response::insertSelectedFields(std::vector<std::string> substrings, int tempId, std::shared_ptr<Person> person) const
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
		it++;
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
		it++;
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

void Response::deleteValuesFromVector(std::vector<std::string> fields, std::vector<std::string> values, class Person* tempPerson)
{
	if (fields[0] == "id") {
		for (int i = 0; i < data.size(); i++) {
			tempPerson = (Person*)data[i];
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
			tempPerson = (Person*)data[i];
			string tempSurname = values[0];
			if (tempPerson->surname == tempSurname) {
				auto deleteItem = data.begin() + i;
				data.erase(deleteItem);
			}
		}
	}
	else if (fields[0] == "name") {
		for (int i = 0; i < data.size(); i++) {
			tempPerson = (Person*)data[i];
			string tempName = values[0];
			if (tempPerson->name == tempName) {
				auto deleteItem = data.begin() + i;
				data.erase(deleteItem);
			}
		}
	}
	else if (fields[0] == "age") {
		for (int i = 0; i < data.size(); i++) {
			tempPerson = (Person*)data[i];
			int tempAge;
			std::istringstream(values[0]) >> tempAge;
			if (tempPerson->age == tempAge) {
				auto deleteItem = data.begin() + i;
				data.erase(deleteItem);
			}
		}
	}
}

void Response::updateValuesFromVector(std::vector<std::string> fields, std::vector<std::string> const &changedFields, std::vector<std::string> const &newValues, std::vector<std::string> values, class Person* tempPerson)
{
	if (fields[0] == "id") {
		for (int i = 0; i < data.size(); i++) {
			tempPerson = (Person*)data[i];
			int tempId;
			std::istringstream(values[0]) >> tempId;
			if (tempPerson->id == tempId) {
				setValue(changedFields, newValues, tempPerson, i);
			}
		}
	}
	else if (fields[0] == "surname") {
		for (int i = 0; i < data.size(); i++) {
			tempPerson = (Person*)data[i];
			string tempSurname = values[0];
			if (tempPerson->surname == tempSurname) {
				setValue(changedFields, newValues, tempPerson, i);
			}
		}
	}
	else if (fields[0] == "name") {
		for (int i = 0; i < data.size(); i++) {
			tempPerson = (Person*)data[i];
			string tempName = values[0];
			if (tempPerson->name == tempName) {
				setValue(changedFields, newValues, tempPerson, i);
			}
		}
	}
	else if (fields[0] == "age") {
		for (int i = 0; i < data.size(); i++) {
			tempPerson = (Person*)data[i];
			int tempAge;
			std::istringstream(values[0]) >> tempAge;
			if (tempPerson->age == tempAge) {
				setValue(changedFields, newValues, tempPerson, i);
			}
		}
	}
}

void Response::setValue(std::vector<std::string> changedFields, std::vector<std::string> newValues, class Person* tempPerson, int i)
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
	data[i] = tempPerson;
}

void Response::selectData(string request)
{
	std::vector<std::shared_ptr<Person>> ptrs;
	data.clear();
	string temp;
	ifstream in("person.txt", ios::in);
	int shift = 0;
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
			
			auto newperson = person.get();

			data.push_back((Data*)newperson);
			shift++;
		}
	}


	vector<string> substrings;
	string delim = " ";


	int pos = 0;
	while ((pos = static_cast<int>(request.find(delim)))!= std::string::npos) {
		substrings.push_back(request.substr(0, pos));
		request.erase(0, pos + delim.length());
	}
	substrings.push_back(request.substr(0, request.size()));

	vector<string> whereFields;
	vector<string> values;
	string itStr;
	if (auto it = std::ranges::find(substrings.begin(), substrings.end(), "WHERE"); it != substrings.end()) {
		it++;
		while (it != substrings.end()) {
			itStr = *it;
			whereFields.push_back(itStr);
			it += 2;
			itStr = *it;
			values.push_back(itStr);
			it++;
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
		cout <<"|" << std::format("{: ^10}", "id") << std::format("{: >10}", '|') << std::format("{: ^17}", "surname") << std::format("{: >10}", '|') << std::format("{: ^14}", "name") << std::format("{: >10}", '|') << std::format("{: ^13}", "age") << std::format("{: >10}", '|') << endl;
		cout << "-----------------------------------------------------------------------------------------------" << endl;
		for (int i = 0; i < data.size(); i++) {
			if (!whereFields.empty()) {

				printDataWithCondition(whereFields, values, fields, data[i]);
				
			}
			else {
				Person person = *(Person*)data[i];
				person.print(fields);
				cout << "-----------------------------------------------------------------------------------------------" << endl;
			}
		}
	}
	else {

		auto posOfFrom = find(substrings.begin(), substrings.end(), "FROM");
		vector<string> fields;

		while (it != posOfFrom) {
			temp = *it;
			if (temp[temp.size() - 1] == ',') {
				temp.erase(temp.size() - 1);
			}
			fields.push_back(temp);
			it++;
		}

		printSelectedFields(fields);
	}
	
}

void Response::insertData(string request)
{
	std::vector<std::shared_ptr<Person>> ptrs;
	
	vector<string> substrings;
	string delim = " ";
	int pos = 0;
	while ((pos = static_cast<int>(request.find(delim))) != std::string::npos) {
		substrings.push_back(request.substr(0, pos));
		request.erase(0, pos + delim.length());
	}
	substrings.push_back(request.substr(0, request.size()));

	string temp;
	int tempId=0;
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

			shared_ptr<Data> object = std::dynamic_pointer_cast<Data>(person);

			data.push_back(object.get());
		}
	}
	in.close();
	if (substrings[1] == "INTO") {
		auto person = make_shared<Person>();
		ptrs.push_back(person);
		person->id = tempId + 1;
		substrings[4].erase(0, 2);
		substrings[4].erase(substrings[4].size()-2, 2);
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
				out <<endl<< person->id << endl;
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
}

void Response::deleteData(string request)
{
	std::vector<std::shared_ptr<Person>> ptrs;
	data.clear();
	string temp;
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

			shared_ptr<Data> object = std::dynamic_pointer_cast<Data>(person);

			data.push_back(object.get());
		}
	}
	in.close();

	vector<string> substrings;
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

	vector<string> fields;
	vector<string> values;
	string itStr;
	auto it = std::ranges::find(substrings.begin(), substrings.end(), "WHERE");
	if (it != substrings.end()) {
		it++;
		while (it != substrings.end()) {
			itStr = *it;
			fields.push_back(itStr);
			it +=2;
			itStr = *it;
			values.push_back(itStr);
			it++;
		}
	}
	else {
		cout << "wrong request!" << endl;
		return;
	}

	auto tempPerson = new Person();

	deleteValuesFromVector(fields, values, tempPerson);

	ofstream out("person.txt", ios::out);
	if (out.is_open()) {
		for (int i = 0; i < data.size(); i++) {
			tempPerson = (Person*)data[i];
			out << tempPerson->id << endl;
			out << tempPerson->surname << endl;
			out << tempPerson->name << endl;
			if (i == data.size() - 1) {
				out << tempPerson->age;
			}
			else {
				out << tempPerson->age<<endl;
			}
		}
		
	}
	out.close();
}

void Response::updateData(string request)
{
	std::vector<std::shared_ptr<Person>> ptrs;
	data.clear();
	string temp;
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


			shared_ptr<Data> object = std::dynamic_pointer_cast<Data>(person);

			data.push_back(object.get());
		}
	}
	in.close();

	vector<string> substrings;
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

	vector<string> changedFields;
	vector<string> newValues;
	vector<string> fields;
	vector<string> values;
	string itStr;
	
	if (auto it = std::ranges::find(substrings.begin(), substrings.end(), "SET"); it != substrings.end()) {
		it++;
		while (*it != "WHERE") {
			itStr = *it;
			changedFields.push_back(itStr);
			it += 2;
			itStr = *it;
			newValues.push_back(itStr);
			it++;
		}
		it++;
		while (it != substrings.end()) {
			itStr = *it;
			fields.push_back(itStr);
			it += 2;
			itStr = *it;
			values.push_back(itStr);
			it++;
		}
	}
	else {
		cout << "wrong request!" << endl;
		return;
	}

	auto tempPerson = new Person();

	updateValuesFromVector(fields, changedFields, newValues, values, tempPerson);

	ofstream out("person.txt", ios::out);
	if (out.is_open()) {
		for (int i = 0; i < data.size(); i++) {
			tempPerson = (Person*)data[i];
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

