#include <windows.h>
#include <tchar.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_CREATE: {

        CreateWindow(TEXT("edit"), NULL,
            WS_VISIBLE | WS_CHILD | WS_BORDER,
            30, 10,
            200, 30,
            hwnd, (HMENU)1, NULL, NULL);


        CreateWindow(TEXT("button"), TEXT("Показать текст"),
            WS_VISIBLE | WS_CHILD,
            30, 50,
            200, 30,
            hwnd, (HMENU)2, NULL, NULL);
        break;
    }
    case WM_COMMAND: {
        if (LOWORD(wParam) == 2) {
            TCHAR text[100];
            GetDlgItemText(hwnd, 1, text, 100);
            if (_tcscmp(text, _T("name")) == 0) {
                MessageBox(hwnd, _T("Серко Александра"), TEXT("Текст"), MB_OK);
            }
            else {
                MessageBox(hwnd, text, TEXT("Текст"), MB_OK);
            }
        }
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