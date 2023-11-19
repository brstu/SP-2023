#include "Person.h"
#include <iostream>
#include <iomanip>

using namespace std;

void Person::print(vector<string> fields)
{
	vector<string>::iterator it;
	cout << "|";
	it = find(fields.begin(), fields.end(), "id");
	if (it != fields.end()) {
		cout << setw(10) << id << setw(10) << "|";
	}
	it = find(fields.begin(), fields.end(), "surname");
	if (it != fields.end()) {
		cout << setw(17) << surname << setw(10) << "|";
	}
	it = find(fields.begin(), fields.end(), "name");
	if (it != fields.end()) {
		cout << setw(14) << name << setw(10) << "|";
	}
	it = find(fields.begin(), fields.end(), "age");
	if (it != fields.end()) {
		cout << setw(13) << age << setw(10) << "|";
	}
	cout << endl;
}
