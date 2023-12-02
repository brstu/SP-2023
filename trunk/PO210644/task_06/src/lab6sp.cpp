#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

void print_tree(const string& path, int level = 0) {
   
    WIN32_FIND_DATAA file_data;
    
    HANDLE h_find = INVALID_HANDLE_VALUE;
    
    string search_path = path + "\\*";
   
    h_find = FindFirstFileA(search_path.c_str(), &file_data);
   
    if (h_find != INVALID_HANDLE_VALUE) {
        
        while (true) {
           
            for (int i = 0; i < level; i++) {
                cout << "  ";
            }
            
            cout << file_data.cFileName << "\n";
            
            if (file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
              
                if (strcmp(file_data.cFileName, ".") != 0 && strcmp(file_data.cFileName, "..") != 0) {
                   
                    string new_path = path + "\\" + file_data.cFileName;
                    
                    print_tree(new_path, level + 1);
                }
            }
           
            if (!FindNextFileA(h_find, &file_data)) {
                break;
            }
        }
        
        FindClose(h_find);
    }
    
    else {
        cout << "Не удалось найти файлы в пути " << path << ".\n";
        cout << "Код ошибки: " << GetLastError() << "\n";
    }
}

void create_file(const string& path) {
    
    HANDLE h_file = CreateFileA(path.c_str(), GENERIC_WRITE, 0, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
    
    if (h_file != INVALID_HANDLE_VALUE) {

        cout << "Файл " << path << " успешно создан.\n";
        
        CloseHandle(h_file);
    }
   
    else {
        cout << "Не удалось создать файл " << path << ".\n";
        cout << "Код ошибки: " << GetLastError() << "\n";
    }
}


void delete_file(const string& path) {
    
    BOOL result = DeleteFileA(path.c_str());
    
    if (result) {
        cout << "Файл " << path << " успешно удален.\n";
    }
   
    else {
        cout << "Не удалось удалить файл " << path << ".\n";
        cout << "Код ошибки: " << GetLastError() << "\n";
    }
}


int main() {

    setlocale(LC_ALL, "Russian");
   
    char current_path[MAX_PATH];
   
    GetCurrentDirectoryA(MAX_PATH, current_path);
   
    int choice = 0;
   
    while (true) {
        
        system("cls");

        cout << "Текущий путь: " << current_path << "\n";
        
        cout << "Выберите действие:\n";
        cout << "1. Перейти в другой каталог\n";
        cout << "2. Вывести дерево каталогов/файлов\n";
        cout << "3. Создать файл\n";
        cout << "4. Удалить файл\n";
        cout << "5. Выйти из программы\n";
        
        cin >> choice;
       
        switch (choice) {
           
        case 1: {
            system("cls");
            cout << "Введите новый путь:\n";
            
            string new_path;
            
            cin >> new_path;
           
            BOOL result = SetCurrentDirectoryA(new_path.c_str());
            
            if (result) {
                GetCurrentDirectoryA(MAX_PATH, current_path);
            }
            
            else {
                cout << "Не удалось перейти в путь " << new_path << ".\n";
                cout << "Код ошибки: " << GetLastError() << "\n";
            }
            system("pause");
            break;
            
        }
             
        case 2: {
            system("cls");
            print_tree(current_path);
            system("pause");
            break;
        }
             
              
        case 3: {
            system("cls");
            cout << "Введите имя файла:\n";
           
            string file_name;
           
            cin >> file_name;
           
            string file_path = string(current_path) + "\\" + file_name;
           
            create_file(file_path);
            system("pause");
            break;
        }
              
        case 4: {
            system("cls");
            cout << "Введите имя файла:\n";
            
            string file_name;
            
            cin >> file_name;
            
            string file_path = string(current_path) + "\\" + file_name;
           
            delete_file(file_path);
            system("pause");
            break;
        }
            
        case 5: {
            system("cls");
            cout << "Программа завершена.\n";
            
            return 0;
        }
              
        default: {
            system("cls");
            cout << "Неверный выбор. Попробуйте еще раз.\n";
            system("pause");
            break;
        }
        }
    }
}
