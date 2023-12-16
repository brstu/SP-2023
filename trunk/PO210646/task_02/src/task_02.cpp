#include <Windows.h>

LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	static HWND hStatic;
	static HWND hEdit;

	switch (msg)
	{
	case WM_CREATE:
	{
		hEdit = CreateWindow(	// поле для ввода
			"eDit",
			"",
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT,
			300, 250, 150, 35,
			hWnd, NULL, NULL, NULL
		);

		HWND hBtn = CreateWindow(	//кнопка
			"BUTTON",
			"CREATE",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			300, 300, 150, 35,
			hWnd, reinterpret_cast<HMENU>(1), NULL, NULL
		);
		break;
	}
	case WM_COMMAND:	//обработчик нажатий
	{
		switch (LOWORD(wparam))
		{
		case 1:
		{
			char buf[20];
			GetWindowTextA(hEdit, buf, 19);
			MessageBoxA(NULL, buf, "CREATE WORD", MB_OK);
			break;
		}
		default:
			break;
		}
		break;
	}
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		break;
	}
	default:
		return DefWindowProc(hWnd, msg, wparam, lparam);
	}
}


int WINAPI WinMain(HINSTANCE hInstanse, HINSTANCE hPrevInstanse, LPSTR lpCmdLine, int nCmdShow)
{
	// дескриптор - тип данных в WINAPI (отвечает за все, например курсора, иконки, окна..)
	HWND hWnd; // дескриптор окна 
	MSG msg;   // дескриптор обработки сообщений в окне
	WNDCLASSEX wc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); // иконка 
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION); // иконка окна
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);	// курсор
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // задний фон цвет
	wc.hInstance = hInstanse; // точка входа
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.lpfnWndProc = WndProc; //
	wc.lpszMenuName = NULL;
	wc.lpszClassName = "WinMainClass";


	RegisterClassEx(&wc);	// регистрируем класс окна
	hWnd = CreateWindow(wc.lpszClassName,
		"Lab_rabot 2",
		WS_OVERLAPPEDWINDOW,
		200, 200, 800, 600,			//координаты относительно левого верхнего угла и размер окна
		NULL, NULL, hInstanse, NULL);

	ShowWindow(hWnd, nCmdShow);	// показ окна
	UpdateWindow(hWnd);			// обновление окна

	while (GetMessage(&msg, NULL, 0, 0))	//обработчик сообщений
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;

}