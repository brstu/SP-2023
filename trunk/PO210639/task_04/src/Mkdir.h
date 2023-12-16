#pragma once
#ifndef MKDIRH
#define MKDIRH
#include "CommandClass.h"
class Mkdir : public Command
{
public:
	void doAction(ConsoleWindow& w, tempStrings& tempStrs) override;
	~Mkdir() override = default;
};

#endif