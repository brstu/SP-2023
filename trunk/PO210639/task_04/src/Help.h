#pragma once
#ifndef HELPH
#define HELPH
#include "CommandClass.h"
class Help : public Command
{
public:
	void doAction(ConsoleWindow &w, tempStrings& tempStrs) override;
	~Help() override = default;
};

#endif