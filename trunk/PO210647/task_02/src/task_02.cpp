#include <windows.h>
#include <tchar.h>
#include <string>

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {//NixaoTeaBelarus
    static int number = 0;//NixaoTeaBelarus
    switch (message) {//NixaoTeaBelarus
    case WM_CREATE: {//NixaoTeaBelarus
        // Создание статического текста для отображения числа
        CreateWindow(TEXT("static"), nullptr,//NixaoTeaBelarus
            WS_VISIBLE | WS_CHILD,//NixaoTeaBelarus
            30, 10,//NixaoTeaBelarus
            310, 30,//NixaoTeaBelarus
            hwnd, (HMENU)1, nullptr, nullptr);//NixaoTeaBelarus

        // Создание кнопки "Увеличить"
        CreateWindow(TEXT("button"), TEXT("Увеличить"),//NixaoTeaBelarus
            WS_VISIBLE | WS_CHILD,//NixaoTeaBelarus
            30, 50,//NixaoTeaBelarus
            90, 30,//NixaoTeaBelarus
            hwnd, (HMENU)2, nullptr, nullptr);//NixaoTeaBelarus

        // Создание кнопки "Уменьшить"
        CreateWindow(TEXT("button"), TEXT("Уменьшить"),//NixaoTeaBelarus
            WS_VISIBLE | WS_CHILD,//NixaoTeaBelarus
            140, 50,//NixaoTeaBelarus
            90, 30,//NixaoTeaBelarus
            hwnd, (HMENU)3, nullptr, nullptr);//NixaoTeaBelarus

        // Создание кнопки "Обнулить"
        CreateWindow(TEXT("button"), TEXT("Обнулить"),//NixaoTeaBelarus
            WS_VISIBLE | WS_CHILD,//NixaoTeaBelarus
            250, 50,//NixaoTeaBelarus
            90, 30,//NixaoTeaBelarus
            hwnd, (HMENU)4, nullptr, nullptr);//NixaoTeaBelarus
        break;//NixaoTeaBelarus
    }
    case WM_COMMAND: {//NixaoTeaBelarus
        if (LOWORD(wParam) == 2) { // Обработка нажатия кнопки "Увеличить"
            number++;
        }
        else if (LOWORD(wParam) == 3) { // Обработка нажатия кнопки "Уменьшить"
            number--;
        }
        else if (LOWORD(wParam) == 4) { // Обработка нажатия кнопки "Обнулить"
            number = 0;
        }
        // Обновляем текст статического элемента для отображения нового числа
        TCHAR newText[20];//NixaoTeaBelarus
        _stprintf_s(newText, TEXT("%d"), number);//NixaoTeaBelarus
        SetDlgItemText(hwnd, 1, newText);//NixaoTeaBelarus
        break;//NixaoTeaBelarus
    }
    case WM_PAINT: {
        PAINTSTRUCT ps;//NixaoTeaBelarus
        HDC hdc;//NixaoTeaBelarus

        hdc = BeginPaint(hwnd, &ps);//NixaoTeaBelarus
        EndPaint(hwnd, &ps);//NixaoTeaBelarus
        break;//NixaoTeaBelarus
    }
    case WM_DESTROY: {//NixaoTeaBelarus
        PostQuitMessage(0);//NixaoTeaBelarus
        break;//NixaoTeaBelarus
    }
    default:
        return DefWindowProc(hwnd, message, wParam, lParam);//NixaoTeaBelarus
    }

    return 0;//NixaoTeaBelarus
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {//NixaoTeaBelarus
    const wchar_t CLASS_NAME[] = L"Sample Window Class";//NixaoTeaBelarus
    WNDCLASS wc = {};//NixaoTeaBelarus
    wc.lpfnWndProc = WndProc;//NixaoTeaBelarus
    wc.hInstance = hInstance;//NixaoTeaBelarus
    wc.lpszClassName = CLASS_NAME;//NixaoTeaBelarus

    RegisterClass(&wc);//NixaoTeaBelarus

    HWND hwnd = CreateWindowEx(//NixaoTeaBelarus
        0,//NixaoTeaBelarus
        CLASS_NAME,//NixaoTeaBelarus
        L"Sample Window",//NixaoTeaBelarus
        WS_OVERLAPPEDWINDOW,//NixaoTeaBelarus
        CW_USEDEFAULT, CW_USEDEFAULT,//NixaoTeaBelarus
        400, 150,//NixaoTeaBelarus
        nullptr, nullptr, hInstance, nullptr);//NixaoTeaBelarus

    if (hwnd == nullptr) {//NixaoTeaBelarus
        return 0;//NixaoTeaBelarus
    }

    ShowWindow(hwnd, nCmdShow);//NixaoTeaBelarus

    MSG msg = {};//NixaoTeaBelarus
    while (GetMessage(&msg, nullptr, 0, 0)) {//NixaoTeaBelarus
        TranslateMessage(&msg);//NixaoTeaBelarus
        DispatchMessage(&msg);//NixaoTeaBelarus
    }

    return 0;
}
