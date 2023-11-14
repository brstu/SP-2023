#ifndef SETTINGS_H
#define SETTINGS_H

class Settings {
public:
	Settings(int s1, int s2, int s3, int s4, int s5);

	int getSetting1() const;
	int getSetting2() const;
	int getSetting3() const;
	int getSetting4() const;
	int getSetting5() const;

	virtual void doAction();

	virtual ~Settings() = default;

private:
	int setting1;
	int setting2;
	int setting3;
	int setting4;
	int setting5;
};
#endif
