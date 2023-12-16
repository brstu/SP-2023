#include "neurologist.h"
#include <iostream>

neurologist::neurologist()
{
	name = "невролог";
	treatmentTime = 0;
	diseaseIndex = 1;
	actions = { " водит молоточком перед глазами ", " бьет молоточком по коленкам " };
}

void neurologist::printInfo()
{
	std::cout << "специальность: " << name << std::endl;
	std::cout << "время лечения: " << treatmentTime << std::endl;
	std::cout << "лечит: невроз" << std::endl;
}
