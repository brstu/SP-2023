#pragma once
#ifndef DIRH
#define DIRH
#include "CommandClass.h"
class Dir : public Command
{
public:
	void doAction(ConsoleWindow& w, tempStrings& tempStrs) override;
	virtual ~Dir() = default;
};

#endif