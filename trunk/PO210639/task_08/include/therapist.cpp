#include "therapist.h"

therapist::therapist()
{
	name = "терапевт";
	treatmentTime = 0;
	diseaseIndex = 2;
	actions = { " прикладывает подорожник ", " дает таблетку активированного угля " };
}

void therapist::printInfo()
{
	std::cout << "специальность: " << name << std::endl;
	std::cout << "время лечения: " << treatmentTime << std::endl;
	std::cout << "лечит: простуда" << std::endl;
}
