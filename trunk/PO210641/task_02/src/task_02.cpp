#include <windows.h>
#include <tchar.h>

int number = 0;  // Исходное значение числа

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_CREATE: {
        // Создание статического текста для отображения числа
        CreateWindow(TEXT("static"), NULL,
            WS_VISIBLE | WS_CHILD,
            30, 10,
            200, 30,
            hwnd, (HMENU)1, NULL, NULL);

        // Создание кнопки "Увеличить"
        CreateWindow(TEXT("button"), TEXT("Увеличить"),
            WS_VISIBLE | WS_CHILD,
            30, 50,
            90, 30,
            hwnd, (HMENU)2, NULL, NULL);

        // Создание кнопки "Уменьшить"
        CreateWindow(TEXT("button"), TEXT("Уменьшить"),
            WS_VISIBLE | WS_CHILD,
            140, 50,
            90, 30,
            hwnd, (HMENU)3, NULL, NULL);
        break;
    }
    case WM_COMMAND: {
        if (LOWORD(wParam) == 2) { // Обработка нажатия кнопки "Увеличить"
            number++;
        }
        else if (LOWORD(wParam) == 3) { // Обработка нажатия кнопки "Уменьшить"
            number--;
        }
        // Обновляем текст статического элемента для отображения нового числа
        TCHAR newText[20];
        _stprintf_s(newText, TEXT("%d"), number);
        SetDlgItemText(hwnd, 1, newText);
        break;
    }
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc;

        hdc = BeginPaint(hwnd, &ps);
        EndPaint(hwnd, &ps);
        break;
    }
    case WM_DESTROY: {
        PostQuitMessage(0);
        break;
    }
    default:
        return DefWindowProc(hwnd, message, wParam, lParam);
    }

    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    const wchar_t CLASS_NAME[] = L"Sample Window Class";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        L"Sample Window",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        400, 300,
        nullptr, nullptr, hInstance, nullptr);

    if (hwnd == nullptr) {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    MSG msg = {};
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
