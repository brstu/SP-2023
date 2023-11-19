#include "Person.h"
#include <iostream>
#include <iomanip>
#include <format>

using namespace std;

void Person::print(vector<string> fields)
{
	vector<string>::iterator it;
	cout << "|";
	it = std::ranges::find(fields.begin(), fields.end(), "id");
	if (it != fields.end()) {
		cout << std::format("{: ^10}", id)<< std::format("{: >10}", '|');
	}
	it = std::ranges::find(fields.begin(), fields.end(), "surname");
	if (it != fields.end()) {
		cout << std::format("{: ^17}", surname) << std::format("{: >10}", '|');
	}
	it = std::ranges::find(fields.begin(), fields.end(), "name");
	if (it != fields.end()) {
		cout << std::format("{: ^14}", name) << std::format("{: >10}", '|');
	}
	it = std::ranges::find(fields.begin(), fields.end(), "age");
	if (it != fields.end()) {
		cout << std::format("{: ^13}", age) << std::format("{: >10}", '|');
	}
	cout << endl;
}
