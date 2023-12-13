#include <windows.h>
#include <vector>
#include <string>
#include <ctime>

// Список английских слов
std::vector<std::wstring> englishWords = {
    L"apple", L"banana", L"cat", L"dog", L"elephant", L"fish", L"grape", L"horse", L"ice cream", L"jungle"
};

// Генерация случайного индекса
int getRandomIndex(int maxIndex) {
    return rand() % maxIndex;
}

// Обработчик нажатия кнопки
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_CREATE: {
        // Создание кнопки
        CreateWindow(L"BUTTON", L"Show Random Word", WS_VISIBLE | WS_CHILD, 10, 10, 200, 30, hwnd, (HMENU)1, NULL, NULL);
        // Создание поля для отображения слова
        CreateWindow(L"STATIC", L"", WS_VISIBLE | WS_CHILD, 10, 50, 200, 30, hwnd, (HMENU)2, NULL, NULL);
        break;
    }
    case WM_COMMAND: {
        if (LOWORD(wParam) == 1) {
            // При нажатии на кнопку
            int randomIndex = getRandomIndex(englishWords.size());
            SetDlgItemTextW(hwnd, 2, englishWords[randomIndex].c_str());
        }
        break;
    }
    case WM_DESTROY: {
        PostQuitMessage(0);
        break;
    }
    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    srand(time(NULL));

    // Регистрация класса окна
    WNDCLASSW wc = { 0 };
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"RandomWordApp";
    RegisterClassW(&wc);

    // Создание окна
    HWND hwnd = CreateWindowW(L"RandomWordApp", L"Random Word App", WS_OVERLAPPEDWINDOW, 100, 100, 300, 150, NULL, NULL, hInstance, NULL);
    ShowWindow(hwnd, nCmdShow);

    // Цикл обработки сообщений
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}