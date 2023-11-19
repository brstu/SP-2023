#include "Dir.h"
#include <iostream>
#include "tempStrings.h"
#include <vector>

void Dir::doAction(ConsoleWindow& w, tempStrings& tempStrs)
{
	int memory = 0;
	for(folder var : tempStrs.folders) {
		if (var.parent == tempStrs.currentPath) {
			std::cout << var.name << std::endl;
			memory += sizeof(var);
		}
	}
	w.doWork(memory);
}
