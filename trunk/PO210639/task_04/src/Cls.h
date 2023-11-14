#pragma once
#ifndef CLSH
#define CLSH
#include "CommandClass.h"
class Cls : public Command
{
public:
	void doAction(ConsoleWindow &w, tempStrings& tempStrs) override;
	~Cls() override = default;
};

#endif