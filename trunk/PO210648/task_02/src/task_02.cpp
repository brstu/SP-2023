#include <windows.h>
#include <iostream>

HWND hWnd;
HWND hButton;
HWND hLabel;

int value = 0;

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// Регистрация класса окна
	WNDCLASSEX wc = {};
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.lpszClassName = L"MainWindow";
	RegisterClassEx(&wc);

	// Создание главного окна
	hWnd = CreateWindowEx(0, wc.lpszClassName, L"Лабораторная работа 2", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 300, 200, NULL, NULL, hInstance, NULL);
	if (!hWnd)
	{
		return -1;
	}

	// Создание кнопки
	hButton = CreateWindow(L"BUTTON", L"Увеличить", WS_VISIBLE | WS_CHILD,
		200, 40, 70, 50, hWnd, (HMENU)2, hInstance, NULL);
	hButton = CreateWindow(L"BUTTON", L"Увеличить", WS_VISIBLE | WS_CHILD,
		30, 40, 70, 50, hWnd, (HMENU)1, hInstance, NULL);

	// Создание метки для отображения числа
	hLabel = CreateWindow(L"STATIC", L"0", WS_VISIBLE | WS_CHILD,
		125, 40, 70, 50, hWnd, NULL, hInstance, NULL);

	ShowWindow(hWnd, nCmdShow);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND:
		if (LOWORD(wParam)==2)
		{
			value++;
			wchar_t text[10];
			swprintf_s(text, L"%d", value);
			SetWindowText(hLabel, text);
		}
		if (LOWORD(wParam) == 1)
		{
			value--;
			wchar_t text[10];
			swprintf_s(text, L"%d", value);
			SetWindowText(hLabel, text);
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}