#include <iostream>
#include "ConsoleWindow.h"
#include "Color.h"
#include "Cls.h"
#include "Help.h"
#include <string>
#include "folder.h"
#include "Dir.h"
#include "Mkdir.h"
#include "Cd.h"
#include "tempStrings.h"

using namespace std;

bool checkCdPath(tempStrings& tempStrs);

int main()
{
	setlocale(LC_ALL, "Rus");
	tempStrings tempStrs;
	string command;
	string temp;
	string outputStr = "\\>";
	folder f1("programms", "D:");
	folder f2("programm files", "C:");
	tempStrs.folders.push_back(f1);
	tempStrs.folders.push_back(f2);
	ConsoleWindow console(200, 150, false, true, true);
	while (true) {
		cout << tempStrs.currentPath+outputStr;
		getline(cin, temp, '\n');
		command = "";
		int i = 0;
		while (temp[i] != ' ' && i != temp.size()) {
			command += temp[i];
			i++;
		}
		if (command == "cls") {
			Cls c;
			console.commandList.push_back(&c);
			c.doAction(console, tempStrs);
		}
		else if (command == "help") {
			Help h;
			console.commandList.push_back(&h);
			h.doAction(console, tempStrs);
		}
		else if (command == "color") {
			string color = "";
			color += temp[temp.size()-1];
			Color c((int)color[0]);
			console.commandList.push_back(&c);
			c.doAction(console, tempStrs);
		}
		else if (command == "C:" || command == "D:") {
			tempStrs.currentDisk = command;
			tempStrs.currentPath = command;
		}
		else if (command == "dir") {
			Dir d;
			console.commandList.push_back(&d);
			d.doAction(console, tempStrs);
		}
		else if (command == "mkdir") {
			tempStrs.newFolderName = "";
			i++;
			while (i != temp.size()) {
				tempStrs.newFolderName += temp[i];
				i++;
			}
			Mkdir md;
			console.commandList.push_back(&md);
			md.doAction(console, tempStrs);
		}
		else if (command == "cd") {
			tempStrs.cdPath = "";
			i++;
			while (i != temp.size()) {
				tempStrs.cdPath += temp[i];
				i++;
			}

			if (!checkCdPath(tempStrs)) {
				continue;
			}
			Cd c;
			console.commandList.push_back(&c);
			c.doAction(console, tempStrs);
		}
		else if (command == "exit") {
			console.ShowOrHide();
			return 0;
		}
		else {
			cout << "используйте команду help для получения сведений о командах" << endl;
		}
	}
}

bool checkCdPath(tempStrings& tempStrs) {
	if (tempStrs.cdPath == "..") {

		string path = "";
		int j = static_cast<int>(tempStrs.currentPath.size()) - 1;

		while (j >= 0 && tempStrs.currentPath[j] != '\\') {
			j--;
		}
		if (j < 0) {
			return false;
		}
		for (int l = 0; l < j; l++) {
			path += tempStrs.currentPath[l];
		}
		tempStrs.currentPath = path;
		return false;
	}
	else if (tempStrs.cdPath[0] == '.' && tempStrs.cdPath[1] == '\\') {
		string path = tempStrs.currentPath;
		for (int l = 1; l < tempStrs.cdPath.size(); l++) {
			path += tempStrs.cdPath[l];
		}
		tempStrs.currentPath = path;
	}
	else if (tempStrs.cdPath[0] != 'C' && tempStrs.cdPath[1] != ':') {
		tempStrs.cdPath = tempStrs.currentPath + '\\' + tempStrs.cdPath;
	}
	return true;
}