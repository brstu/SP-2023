#include "lor.h"
#include <iostream>

lor::lor()
{
	name = "Lor";
	maxTime = 0;
	
	illnessNum= 3;
	methods = { " Examines ears and washes out studs ", " prescribes ear drops " };
}

void lor::getData()
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Treatment time: " << maxTime << std::endl;
	std::cout << "Treament methods" << methods[0] << methods[1] << std::endl;
	std::cout << "Treats ear, throat and nose problems" << std::endl;

}