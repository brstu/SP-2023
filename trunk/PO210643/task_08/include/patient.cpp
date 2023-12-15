
#include "patient.h"

patient::patient() : name("")
{
}

patient::patient(const std::string& _name) : name(_name) {
}

void patient::getData()
{
	std::cout << "Patient Name: " << name << std::endl;
	std::cout << "Illness: ";
	for (int var : illnesses) {
		std::cout << illnessMap[var - 1] << " ";
	}
	std::cout << std::endl;
}