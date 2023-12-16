#include "cardiologist.h"
#include <iostream>

cardiologist::cardiologist()
{
	name = "Cardiologist";
	maxTime = 0;
	illnessNum = 1;
	methods = { " performs computer tomography ", " prescribes medicines " };

}

void cardiologist::getData()
{
	std::cout << "Speciality: " << name << std::endl;
	std::cout << "Treatment time: " << maxTime << std::endl;
	std::cout << "Treament methods" << methods[0] << methods[1]<<   std::endl;
	std::cout << "Treats heart disease" << std::endl;

}