#include "Help.h"
#include <string>
#include <iostream>
#include "tempStrings.h"

using namespace std;

void Help::doAction(ConsoleWindow &w, tempStrings& tempStrs)
{
	string answer = "cd - Вывод имени либо смена текущей папки\ncls - очистка экрана\ndir - вывод списка файлов и подпапок из указанной папки\nhelp - выводит справочную информацию о командах\nmkdir - создает каталог\ncolor - изменяет цвет фона консоли";
	cout << answer << endl;
	w.doWork(sizeof(answer));
}
