#include "psychiatrist.h"

psychiatrist::psychiatrist()
{
	name = "психиатр";
	treatmentTime = 0;
	diseaseIndex = 3;
	actions = { " помогает найти смысл жизни ", " надевает смирительную рубашку на " };
}

void psychiatrist::printInfo()
{
	std::cout << "специальность: " << name << std::endl;
	std::cout << "время лечения: " << treatmentTime << std::endl;
	std::cout << "лечит: депрессия" << std::endl;
}
