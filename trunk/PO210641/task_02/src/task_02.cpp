#include <windows.h>
#include <tchar.h>

const int initialNumber = 0;
int number = initialNumber;

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_CREATE: {
        // Создание статического текста для отображения числа
        CreateWindow(TEXT("static"), nullptr,
            WS_VISIBLE | WS_CHILD,
            30, 10,
            310, 30,
            hwnd, (HMENU)1, nullptr, nullptr);

        // Создание кнопки "Увеличить"
        CreateWindow(TEXT("button"), TEXT("Увеличить"),
            WS_VISIBLE | WS_CHILD,
            30, 50,
            90, 30,
            hwnd, (HMENU)2, nullptr, nullptr);

        // Создание кнопки "Уменьшить"
        CreateWindow(TEXT("button"), TEXT("Уменьшить"),
            WS_VISIBLE | WS_CHILD,
            140, 50,
            90, 30,
            hwnd, (HMENU)3, nullptr, nullptr);

        // Создание кнопки "Обнулить"
        CreateWindow(TEXT("button"), TEXT("Обнулить"),
            WS_VISIBLE | WS_CHILD,
            250, 50,
            90, 30,
            hwnd, (HMENU)4, nullptr, nullptr);
        break;
    }
    case WM_COMMAND: {
        if (LOWORD(wParam) == 2) { // Обработка нажатия кнопки "Увеличить"
            number++;
        }
        else if (LOWORD(wParam) == 3) { // Обработка нажатия кнопки "Уменьшить"
            number--;
        }
        else if (LOWORD(wParam) == 4) { // Обработка нажатия кнопки "Обнулить"
            number = initialNumber;
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
        400, 150,
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
