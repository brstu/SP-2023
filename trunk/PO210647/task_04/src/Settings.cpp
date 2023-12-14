#include "Settings.h"

Settings::Settings(int s1, int s2, int s3, int s4, int s5)//1
	: setting1(s1), setting2(s2), setting3(s3), setting4(s4), setting5(s5) {//1
}//1

int Settings::getSetting1() const//1
{//1
	return setting1;//1
}

int Settings::getSetting2() const//1
{
	return setting2;//1
}

int Settings::getSetting3() const//1
{//1
	return setting3;//1
}

int Settings::getSetting4() const//1
{
	return setting4;//1
}

int Settings::getSetting5() const//1
{
	return setting5;//1
}

void Settings::doAction() {
	//1
}