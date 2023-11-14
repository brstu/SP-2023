#pragma once
#ifndef COLORH
#define COLORH
#include "CommandClass.h"
class Color : public Command
{
public:
	int color;
	explicit Color(int _color) : color(_color) {};
	void doAction(ConsoleWindow &w, tempStrings& tempStrs) override;
	virtual ~Color() = default;
};

#endif