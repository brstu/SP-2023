#include "Cd.h"
#include <iostream>
#include "tempStrings.h"

void Cd::doAction(ConsoleWindow& w, tempStrings& tempStrs)
{
	std::string temp = "";
	std::string folderName = "";
	std::string parentPath = "";
	int i = static_cast<int>(tempStrs.cdPath.size()) - 1;
	while (i>=0 && tempStrs.cdPath[i] != '\\'){
		temp += tempStrs.cdPath[i];
		i--;
	}
	for (int j = static_cast<int>(temp.size()) - 1; j >= 0; j--) {
		folderName += temp[j];
	}
	for (int j = 0; j < i; j++) {
		parentPath += tempStrs.cdPath[j];
	}
	if (folderName == "") {
		tempStrs.currentPath = parentPath;
	}
	else {
		for (folder var : tempStrs.folders) {
			if (var.name == folderName && var.parent == parentPath) {
				tempStrs.currentPath = tempStrs.cdPath;
				return;
			}
		}
	}
	w.doWork(sizeof(tempStrs.currentPath));
}
