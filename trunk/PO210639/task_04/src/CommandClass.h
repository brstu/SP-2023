#pragma once
#ifndef COMMANDH
#define COMMANDH
#include "ConsoleWindow.h"
#include "folder.h"
#include "tempStrings.h"

class Command
{
public:
	virtual void doAction(ConsoleWindow &w, tempStrings &tempStrs) = 0;
	virtual ~Command() = default;
};

#endif