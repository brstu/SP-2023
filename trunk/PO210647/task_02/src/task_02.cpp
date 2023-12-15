#include <windows.h>
#include <tchar.h>
#include <string>

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {//210647
    static int number = 0;//210647
    switch (message) {//210647
    case WM_CREATE: {//210647
        // Создание статического текста для отображения числа
        CreateWindow(TEXT("static"), nullptr,//210647
            WS_VISIBLE | WS_CHILD,//210647
            30, 10,//210647
            310, 30,//210647
            hwnd, (HMENU)1, nullptr, nullptr);//210647

        // Создание кнопки "Увеличить"
        CreateWindow(TEXT("button"), TEXT("Увеличить"),//210647
            WS_VISIBLE | WS_CHILD,//210647
            30, 50,//210647
            90, 30,//210647
            hwnd, (HMENU)2, nullptr, nullptr);//210647

        // Создание кнопки "Уменьшить"
        CreateWindow(TEXT("button"), TEXT("Уменьшить"),//210647
            WS_VISIBLE | WS_CHILD,//210647
            140, 50,//210647
            90, 30,//210647
            hwnd, (HMENU)3, nullptr, nullptr);//210647

        // Создание кнопки "Обнулить"
        CreateWindow(TEXT("button"), TEXT("Обнулить"),//210647
            WS_VISIBLE | WS_CHILD,//210647
            250, 50,//210647
            90, 30,//210647
            hwnd, (HMENU)4, nullptr, nullptr);//210647
        break;//210647
    }//210647
    case WM_COMMAND: {//210647
        if (LOWORD(wParam) == 2) { // Обработка нажатия кнопки "Увеличить"
            number++;//210647
        }
        else if (LOWORD(wParam) == 3) { // Обработка нажатия кнопки "Уменьшить"//210647
            number--;//210647
        }
        else if (LOWORD(wParam) == 4) { // Обработка нажатия кнопки "Обнулить"//210647
            number = 0;//210647
        }
        // Обновляем текст статического элемента для отображения нового числа
        TCHAR newText[20];//210647
        _stprintf_s(newText, TEXT("%d"), number);//210647
        SetDlgItemText(hwnd, 1, newText);//210647
        break;//210647
    }//210647
    case WM_PAINT: {//210647
        PAINTSTRUCT ps;//210647
        HDC hdc;//210647

        hdc = BeginPaint(hwnd, &ps);//210647
        EndPaint(hwnd, &ps);//210647
        break;//210647
    }//210647
    case WM_DESTROY: {//210647
        PostQuitMessage(0);//210647
        break;//210647
    }
    default://210647
        return DefWindowProc(hwnd, message, wParam, lParam);//210647
    }

    return 0;//210647
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {//210647
    const wchar_t CLASS_NAME[] = L"Sample Window Class";//210647
    WNDCLASS wc = {};//210647
    wc.lpfnWndProc = WndProc;//210647
    wc.hInstance = hInstance;//210647
    wc.lpszClassName = CLASS_NAME;//210647

    RegisterClass(&wc);//210647

    HWND hwnd = CreateWindowEx(//210647
        0,//210647
        CLASS_NAME,//210647
        L"Sample Window",//210647
        WS_OVERLAPPEDWINDOW,//210647
        CW_USEDEFAULT, CW_USEDEFAULT,//210647
        400, 150,//210647
        nullptr, nullptr, hInstance, nullptr);//210647

    if (hwnd == nullptr) {//210647
        return 0;//210647
    }

    ShowWindow(hwnd, nCmdShow);//210647

    MSG msg = {};//210647
    while (GetMessage(&msg, nullptr, 0, 0)) {//210647
        TranslateMessage(&msg);//210647
        DispatchMessage(&msg);//210647
    }

    return 0;//210647
}
