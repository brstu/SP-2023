#pragma once
#ifndef CDH
#define CDH
#include "CommandClass.h"
#include "tempStrings.h"

class Cd : public Command
{
public:
	void doAction(ConsoleWindow& w, tempStrings& tempStrs) override;
	virtual ~Cd()=default;
};

#endif