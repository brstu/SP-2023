
# Лабораторная работа №2 #

## Создание программы с графическим пользовательским интерфейсом в ОС Windows ##

## Вариант 5 ##

## Реализация/ход работы ##

### Цель работы: Научиться создавать простейшие приложения с графическим пользовательским интерфейсом в ОС Windows ###

#### **Условие** ####

Создaть приложение с двумя кнопками и полем для отображения числа. По нажатию на кнопки число должно увеличивaться или уменьшaться в зависимости от нажатой кнопки.

Создание статического текста для отображения числа:

``` c++
CreateWindow(TEXT("static"), NULL,
    WS_VISIBLE | WS_CHILD,
    30, 10,
    310, 30,
    hwnd, (HMENU)1, NULL, NULL);
```

Создание кнопки для увеличения числа:

``` c++
CreateWindow(TEXT("button"), TEXT("Увеличить"),
    WS_VISIBLE | WS_CHILD,
    30, 50,
    90, 30,
    hwnd, (HMENU)2, NULL, NULL);
```

Создание кнопки для уменьшения числа:

``` c++
CreateWindow(TEXT("button"), TEXT("Уменьшить"),
    WS_VISIBLE | WS_CHILD,
    140, 50,
    90, 30,
    hwnd, (HMENU)3, NULL, NULL);
```

Обработка нажатия кнопки:

``` c++
if (LOWORD(wParam) == 2) { // Обработка нажатия кнопки "Увеличить"
    number++;
}
else if (LOWORD(wParam) == 3) { // Обработка нажатия кнопки "Уменьшить"
    number--;
}
```

Обновление текста статического элемента для отображения нового числа:

``` c++
TCHAR newText[20];
_stprintf_s(newText, TEXT("%d"), number); 
SetDlgItemText(hwnd, 1, newText);
break;
```

Регистрация класса окна:

``` c++
const wchar_t CLASS_NAME[] = L"Sample Window Class";
WNDCLASS wc = {};
wc.lpfnWndProc = WndProc;
wc.hInstance = hInstance;
wc.lpszClassName = CLASS_NAME;
```

Создание окна:

``` c++
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
```

Основной цикл обработки сообщений:

``` c++
MSG msg = {};
while (GetMessage(&msg, nullptr, 0, 0)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
}
```

#### Результат работы программы ####

Увеличение числа:

![img.png](images/img.png)

Уменьшение числа:

![img_1.png](images/img_1.png)

#### Вывод ####

Научились создавать простейшие приложения с графическим пользовательским интерфейсом в ОС Windows.
