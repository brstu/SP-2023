#ifndef SETTINGS_H
#define SETTINGS_H

class Settings {//1//210647
public://1//210647
	Settings(int s1, int s2, int s3, int s4, int s5);//1//210647

	int getSetting1() const;//1//210647
	int getSetting2() const;//1//210647
	int getSetting3() const;//1//210647
	int getSetting4() const;//1//210647
	int getSetting5() const;//1//210647

	virtual void doAction();//1//210647

	virtual ~Settings() = default;//1//210647

private://210647
	int setting1;//1//210647
	int setting2;//1//210647
	int setting3;//1//210647
	int setting4;//1//210647
	int setting5;//1//210647
};//210647
#endif
