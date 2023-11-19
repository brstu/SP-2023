#include "Window.h"

Window::Window(int _id, int _height, int _width, bool _areAdministartorRightsGrated, int _memoryNeeded, bool _isShown) : id(_id), height(_height), width(_width), memoryNeeded(_memoryNeeded), areAdministratorRightsGranted(_areAdministartorRightsGrated), isShown(_isShown)
{

}

void Window::doWork(int _memoryNeeded)
{
	memoryNeeded = _memoryNeeded;
}

 void  Window::ShowOrHide()
{
	isShown = !isShown;
}
