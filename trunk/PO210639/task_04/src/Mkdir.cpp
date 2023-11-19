#include "Mkdir.h"
#include <iostream>
#include "tempStrings.h"

using namespace std;

void Mkdir::doAction(ConsoleWindow& w, tempStrings& tempStrs)
{
	folder f(tempStrs.newFolderName, tempStrs.currentPath);
	tempStrs.folders.push_back(f);
	w.doWork(sizeof(f));
}
