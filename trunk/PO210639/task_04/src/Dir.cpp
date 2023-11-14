#include "Dir.h"
#include <iostream>
#include "tempStrings.h"

using namespace std;

void Dir::doAction(ConsoleWindow& w, tempStrings& tempStrs)
{
	int memory = 0;
	for (int i = 0; i < tempStrs.folders.size(); i++) {
		if (tempStrs.folders[i].parent == tempStrs.currentPath) {
			cout << tempStrs.folders[i].name << endl;
			memory += sizeof(tempStrs.folders[i]);
		}
	}
	w.doWork(memory);
}
