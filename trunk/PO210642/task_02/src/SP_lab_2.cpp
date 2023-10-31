#include "framework.h"
#include "SP_lab_2.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst; // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING]; // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING]; // имя класса главного окна

const std::vector<std::string> names = {
    "Kate", "Valeria", "Iliya", "Alexandra", "Yakov",
    "Egor", "Maria", "Nastya"
};

// Прототипы функций
ATOM MyRegisterClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE, int, HWND&);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void ShowRandomName(HWND);

// Главная функция
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR lpCmdLine,
    _In_ int nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // Загружаем строку заголовка и имя класса из ресурсов
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_SPLAB2, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance); // Регистрируем класс окна

    HWND hWnd;

    if (!InitInstance(hInstance, nCmdShow, hWnd))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SPLAB2));

    MSG msg;

    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int)msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SPLAB2));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_SPLAB2);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

// Инициализация экземпляра и создание окна
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow, HWND& hWnd)
{
    hInst = hInstance;

    // Создаем главное окно
    hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, 210, 200, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    // Показываем окно
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

// Обработка сообщений окна
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
    {
        // Создаем кнопку и поле для отображения имени в блоке WM_CREATE
        CreateWindow(TEXT("static"), nullptr,
            WS_VISIBLE | WS_CHILD | ES_CENTER,
            50, 20, 100, 30,
            hWnd, (HMENU)2, nullptr, nullptr);

        CreateWindow(TEXT("button"), TEXT("Click me!"),
            WS_VISIBLE | WS_CHILD,
            50, 60, 100, 30,
            hWnd, (HMENU)1, nullptr, nullptr);
    }
    break;
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        switch (wmId)
        {
        case IDM_ABOUT:
        {
            // Показываем случайное имя при нажатии на кнопку или выборе пункта меню IDM_ABOUT
            ShowRandomName(hWnd);
        }
        break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        case 1:
            ShowRandomName(hWnd); // Показываем случайное имя при нажатии на кнопку
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Функция для отображения случайного имени
void ShowRandomName(HWND hWnd)
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int index = rand() % names.size();
    SetWindowTextA(GetDlgItem(hWnd, 2), names[index].c_str());
}

INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
