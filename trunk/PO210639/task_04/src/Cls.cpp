#include "Cls.h"
#include <iostream>
#include "tempStrings.h"

void Cls::doAction(ConsoleWindow &w, tempStrings& tempStrs)
{
	system("cls");
	w.doWork(0);
}
