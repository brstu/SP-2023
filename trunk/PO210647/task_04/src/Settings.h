#ifndef SETTINGS_H
#define SETTINGS_H

class Settings {//1
public://1
	Settings(int s1, int s2, int s3, int s4, int s5);//1

	int getSetting1() const;//1
	int getSetting2() const;//1
	int getSetting3() const;//1
	int getSetting4() const;//1
	int getSetting5() const;//1

	virtual void doAction();//1

	virtual ~Settings() = default;//1

private:
	int setting1;//1
	int setting2;//1
	int setting3;//1
	int setting4;//1
	int setting5;//1
};
#endif
