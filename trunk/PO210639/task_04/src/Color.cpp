#include "Color.h"
#include <iostream>
#include <sstream>
#include "tempStrings.h"

using namespace std;

void Color::doAction(ConsoleWindow &w, tempStrings& tempStrs)
{
	w.color=color;
	string Color;
	Color += (char)color;
	string tempstr = "color " + Color + "f";
	system(tempstr.c_str());
	w.doWork(sizeof(Color));
}
