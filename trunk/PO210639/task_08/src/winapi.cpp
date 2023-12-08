#include "framework.h"
#include "winapi.h"
#include <string.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

int const  MAX_LOADSTRING = 100;


HINSTANCE hInst;
WCHAR szTitle[MAX_LOADSTRING];
WCHAR szWindowClass[MAX_LOADSTRING];

void printInfoToFile();

void readFromFile();

std::vector<HWND> hwnds;

ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINAPI, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINAPI));

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
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINAPI));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINAPI);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance;

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, 460, 480, nullptr, nullptr, hInst, nullptr);

    
    if (!hWnd)
    {
        int Error = GetLastError();
        MessageBox(hWnd, nullptr, std::to_string(Error).c_str(), MB_OK);
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
    {
        HWND hwnd;

        CreateWindow(TEXT("static"), TEXT("Врачи:"),
            WS_VISIBLE | WS_CHILD | ES_CENTER,
            105, 20, 120, 20,
            hWnd, (HMENU)2, nullptr, nullptr);

        CreateWindow(TEXT("static"), TEXT("Специальность:"),
            WS_VISIBLE | WS_CHILD | ES_CENTER,
            50, 50, 110, 20,
            hWnd, (HMENU)3, nullptr, nullptr);

        CreateWindow(TEXT("static"), TEXT("Время_лечения:"),
            WS_VISIBLE | WS_CHILD | ES_CENTER,
            170, 50, 110, 20,
            hWnd, (HMENU)4, nullptr, nullptr);

        CreateWindow(TEXT("static"), TEXT("Невролог"),
            WS_VISIBLE | WS_CHILD | ES_CENTER,
            50, 80, 110, 20,
            hWnd, (HMENU)5, nullptr, nullptr);

        hwnd = CreateWindow(TEXT("edit"), TEXT(""),
            WS_VISIBLE | WS_CHILD | ES_CENTER,
            170, 80, 110, 20,
            hWnd, (HMENU)6, nullptr, nullptr);

        hwnds.push_back(hwnd);

        CreateWindow(TEXT("static"), TEXT("Терапевт"),
            WS_VISIBLE | WS_CHILD | ES_CENTER,
            50, 110, 110, 20,
            hWnd, (HMENU)7, nullptr, nullptr);

        hwnd = CreateWindow(TEXT("edit"), TEXT(""),
            WS_VISIBLE | WS_CHILD | ES_CENTER,
            170, 110, 110, 20,
            hWnd, (HMENU)8, nullptr, nullptr);

        hwnds.push_back(hwnd);

        CreateWindow(TEXT("static"), TEXT("Психиатр"),
            WS_VISIBLE | WS_CHILD | ES_CENTER,
            50, 140, 110, 20,
            hWnd, (HMENU)9, nullptr, nullptr);

        hwnd = CreateWindow(TEXT("edit"), TEXT(""),
            WS_VISIBLE | WS_CHILD | ES_CENTER,
            170, 140, 110, 20,
            hWnd, (HMENU)10, nullptr, nullptr);

        hwnds.push_back(hwnd);

        CreateWindow(TEXT("static"), TEXT("Список_болезней"),
            WS_VISIBLE | WS_CHILD | ES_CENTER,
            300, 20, 110, 20,
            hWnd, (HMENU)11, nullptr, nullptr);

        CreateWindow(TEXT("static"), TEXT("1.Невроз"),
            WS_VISIBLE | WS_CHILD | ES_CENTER,
            300, 50, 110, 20,
            hWnd, (HMENU)12, nullptr, nullptr);

        CreateWindow(TEXT("static"), TEXT("2.Простуда"),
            WS_VISIBLE | WS_CHILD | ES_CENTER,
            300, 80, 110, 20,
            hWnd, (HMENU)13, nullptr, nullptr);

        CreateWindow(TEXT("static"), TEXT("3.Депрессия"),
            WS_VISIBLE | WS_CHILD | ES_CENTER,
            300, 110, 110, 20,
            hWnd, (HMENU)14, nullptr, nullptr);

        CreateWindow(TEXT("static"), TEXT("Пациенты:"),
            WS_VISIBLE | WS_CHILD | ES_CENTER,
            105, 170, 110, 20,
            hWnd, (HMENU)15, nullptr, nullptr);

        CreateWindow(TEXT("static"), TEXT("Имя:"),
            WS_VISIBLE | WS_CHILD | ES_CENTER,
            50, 200, 110, 20,
            hWnd, (HMENU)16, nullptr, nullptr);

        CreateWindow(TEXT("static"), TEXT("Болезни:"),
            WS_VISIBLE | WS_CHILD | ES_CENTER,
            170, 200, 110, 20,
            hWnd, (HMENU)17, nullptr, nullptr);

        hwnd = CreateWindow(TEXT("edit"), TEXT(""),
            WS_VISIBLE | WS_CHILD | ES_CENTER,
            50, 230, 110, 20,
            hWnd, (HMENU)18, nullptr, nullptr);

        hwnds.push_back(hwnd);

        hwnd = CreateWindow(TEXT("edit"), TEXT(""),
            WS_VISIBLE | WS_CHILD | ES_CENTER,
            170, 230, 110, 20,
            hWnd, (HMENU)19, nullptr, nullptr);

        hwnds.push_back(hwnd);

        hwnd = CreateWindow(TEXT("edit"), TEXT(""),
            WS_VISIBLE | WS_CHILD | ES_CENTER,
            50, 260, 110, 20,
            hWnd, (HMENU)20, nullptr, nullptr);

        hwnds.push_back(hwnd);

        hwnd = CreateWindow(TEXT("edit"), TEXT(""),
            WS_VISIBLE | WS_CHILD | ES_CENTER,
            170, 260, 110, 20,
            hWnd, (HMENU)21, nullptr, nullptr);

        hwnds.push_back(hwnd);

        hwnd = CreateWindow(TEXT("edit"), TEXT(""),
            WS_VISIBLE | WS_CHILD | ES_CENTER,
            50, 290, 110, 20,
            hWnd, (HMENU)22, nullptr, nullptr);

        hwnds.push_back(hwnd);

        hwnd = CreateWindow(TEXT("edit"), TEXT(""),
            WS_VISIBLE | WS_CHILD | ES_CENTER,
            170, 290, 110, 20,
            hWnd, (HMENU)23, nullptr, nullptr);

        hwnds.push_back(hwnd);

        hwnd = CreateWindow(TEXT("edit"), TEXT(""),
            WS_VISIBLE | WS_CHILD | ES_CENTER,
            50, 320, 110, 20,
            hWnd, (HMENU)24, nullptr, nullptr);

        hwnds.push_back(hwnd);

        hwnd = CreateWindow(TEXT("edit"), TEXT(""),
            WS_VISIBLE | WS_CHILD | ES_CENTER,
            170, 320, 110, 20,
            hWnd, (HMENU)25, nullptr, nullptr);

        hwnds.push_back(hwnd);

        hwnd = CreateWindow(TEXT("edit"), TEXT(""),
            WS_VISIBLE | WS_CHILD | ES_CENTER,
            50, 350, 110, 20,
            hWnd, (HMENU)26, nullptr, nullptr);

        hwnds.push_back(hwnd);

        hwnd = CreateWindow(TEXT("edit"), TEXT(""),
            WS_VISIBLE | WS_CHILD | ES_CENTER,
            170, 350, 110, 20,
            hWnd, (HMENU)27, nullptr, nullptr);

        hwnds.push_back(hwnd);

        CreateWindow(TEXT("button"), TEXT("Добавить"),
            WS_VISIBLE | WS_CHILD,
            50, 380, 110, 20,
            hWnd, (HMENU)28, nullptr, nullptr);

        CreateWindow(TEXT("button"), TEXT("Извлечь_из_файла"),
            WS_VISIBLE | WS_CHILD,
            170, 380, 110, 20,
            hWnd, (HMENU)29, nullptr, nullptr);
    }
    break;
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        switch (wmId)
        {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        case 28:
            printInfoToFile();
            break;
        case 29:
            readFromFile();
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        BeginPaint(hWnd, &ps);
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
    default:
        break;
    }
    return (INT_PTR)FALSE;
}

void printInfoToFile() {
    std::string str="";
    LPWSTR temp = (LPWSTR)str.c_str();



    for (int i = 0; i < hwnds.size(); i++) {
        GetWindowTextW(hwnds[i], temp, 100);

        std::wstring wString;
        wString.append(&temp[0]);
        std::string tempStr(wString.begin(), wString.end());

        std::ofstream out;
        if (i == 0) {
            out.open("data.txt", std::ios::out);
        }
        else {
            out.open("data.txt", std::ios::app);
        }
        if (out.is_open()) {
            out << tempStr << std::endl;
        }
        out.close();
    }
}

void readFromFile() {
    std::string tempStr;
    std::ifstream in("data.txt", std::ios::in);
    for (HWND var : hwnds) {
        getline(in, tempStr, '\n');
        SetWindowTextA(var, tempStr.c_str());
    }
}