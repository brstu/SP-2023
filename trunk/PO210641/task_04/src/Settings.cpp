#include "Settings.h"

Settings::Settings(int s1, int s2, int s3, int s4, int s5)
	: setting1(s1), setting2(s2), setting3(s3), setting4(s4), setting5(s5) {
}

int Settings::getSetting1() const
{
	return setting1;
}

int Settings::getSetting2() const
{
	return setting2;
}

int Settings::getSetting3() const
{
	return setting3;
}

int Settings::getSetting4() const
{
	return setting4;
}

int Settings::getSetting5() const
{
	return setting5;
}

void Settings::doAction() {
	// This function intentionally left empty because it's not needed in this context.
}