#pragma once
#ifndef WINDOWH
#define WINDOWH

class Window
{
public:
	int id;
	int height;
	int width;
	int memoryNeeded;
	bool areAdministratorRightsGranted;
	bool isShown;
	Window(int _id, int _height, int _width, bool _areAdministartorRightsGrated, int _memoryNeeded = 0, bool _isShown = true);
	void doWork(int _memoryNeeded);
	void  ShowOrHide();
};

#endif