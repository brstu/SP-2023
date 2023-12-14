# Лабораторная работа №6 #

## Разработка консольного приложения в Windows ##

## Цель работы ##

*отработать навыки по созданию консольных приложений в Windows, используя C++.*

## Вариант 1 ##

### Задание ###

***Создать программу-проводник. Программы должна уметь переходить в разные папки, выводить дерево каталогов/файлов, создавать и удалять файлы***

1. Меню:
``` c++
while (true) {
        std::wcout << L"Current directory: " << currentPath << std::endl;
        ListFiles(currentPath);

        std::wstring input;
        std::wcout << L"Enter command (cd <folder>, new <file>, del <file>, q): ";
        std::wcin >> input;

        if (input == L"q") {
            break;
        }
        else if (input == L"cd") {
            std::wcin >> input;
            currentPath += L"\\" + input;
        }
        else if (input == L"new") {
            std::wcin >> input;
            HANDLE newFile = CreateFile((currentPath + L"\\" + input).c_str(), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
            if (newFile != INVALID_HANDLE_VALUE) {
                CloseHandle(newFile);
                std::wcout << L"File created successfully" << std::endl;
            }
            else {
                std::wcout << L"Failed to create file" << std::endl;
            }
        }
        else if (input == L"del") {
            std::wcin >> input;
            if (DeleteFile((currentPath + L"\\" + input).c_str())) {
                std::wcout << L"File deleted successfully" << std::endl;
            }
            else {
                std::wcout << L"Failed to delete file" << std::endl;
            }
        }
    }
```
2. Смена каталога:
``` c++
currentPath += L"\\" + input;
```
3. Создание файла:
``` c++
HANDLE newFile = CreateFile((currentPath + L"\\" + input).c_str(), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
```
4. Удаление файла:
``` c++
DeleteFile((currentPath + L"\\" + input).c_str())
```
5. Результат работы программы

![result.jpg](images/result.jpg)

### Вывод ###

***Создать программу-проводник. Программы должна уметь переходить в разные папки, выводить дерево каталогов/файлов, создавать и удалять файлы***