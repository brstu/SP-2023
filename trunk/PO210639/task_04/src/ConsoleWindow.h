#pragma once
#ifndef CONSOLEWINDOWH
#define CONSOLEWINDOWH
#include "Window.h"
#include "vector"

class Command;

class ConsoleWindow : public Window
{
public:
	ConsoleWindow(int _height, int _width, bool _rights, int _memoryNeeded = 0, bool _isShown = true, int _color = 0);
	int color;
	std::vector<Command*> commandList;
};

#endif