#include "dentist.h"
#include <iostream>

dentist::dentist()
{
	name = "Dentist";
	maxTime = 0;
	illnessNum = 2;
	methods = { " drill into the tooth to get rid of cavity ", " sets brackets " };

}

void dentist::getData()
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Treatment time: " << maxTime << std::endl;
	std::cout << "Treament methods" << methods[0] << methods[1] << std::endl;
	std::cout << "Treats tooth decay and cavity" << std::endl;

}