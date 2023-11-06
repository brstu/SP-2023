## Цель работы

Научиться создавать простейшие классы-наследники.
## Задание
Для выполнения лабораторной работы необходимо создать класс Window. В классе должны быть следующие поля: id (int), height (int), width (int), memoryNeeded (int), areAdministatorRightsGranted (boolean) и isShown (boolean). Требуется реализовать конструктор, задающий id и принимающий параметры height, width и areAdministatorRightsGranted, метод doWork, в котором будет изменяться значение memoryNeeded и метод showOrHide, меняющий значение переменной isShown. Затем необходимо создать класс-наследник класса Window по варианту, реализующий имитацию заданной функциональности.
## Вариант №16 (1)
Создать класс DesktopWindow. В данном классе добавляются поля shortcuts (массив/список ярлыков) и backgroundImagePath. Ярлык реализовать отдельным классом. У ярлыка должен быть id, size, xPosition, yPosition и path. Реализовать методы для перемещения ярлыка и запуска. doWork вызывается только при создании объекта класса и при перемещении ярлыка. MemoryNeeded принимать как неизменяемое значение, зависящее от количества ярлыков. В основной программе реализовать функцию, создающую новый экран и функцию, меняющий активный экран.
## Реализация/ход работы
Класс `Window`:
```C#
public class Window
{
    #region Fields

    private static int _nextId = 0;

    protected int _id;
    protected int _width;
    protected int _height;
    protected int _memoryNeeded;
    protected bool _areAdministatorRightsGranted;
    protected bool _isShown;

    #endregion


    public Window(int width, int height, bool areAdministatorRightsGranted)
    {
        _id = _nextId++;

        _width = width;
        _height = height;
        _areAdministatorRightsGranted = areAdministatorRightsGranted;
    }

    protected virtual void DoWork()
    {
        // do smth
    }

    public void ShowOrHide(bool isShown)
    {
        _isShown = isShown;
    }
}
```
Класс `Shortcut`:
```C#
public class Shortcut
{
    #region Fields

    private int _nextId = 0;

    private int _id;
    private int _size;
    private int _xPosition;
    private int _yPosition;
    private string _path;

    private Action? _parentDoWork = null;

    #endregion

    public Shortcut(int size, int xPosition, int yPosition, string path)
    {
        _id = _nextId++;

        _size = size;
        _xPosition = xPosition;
        _yPosition = yPosition;
        _path = path;
    }

    public void SetParentDoWork(Action action)
    {
        _parentDoWork = action;
    }

    public Process Run()
    {
        var process = Process.Start(_path);

        _parentDoWork?.Invoke();

        return process;
    }

    public void Move(int x, int y)
    {
        _xPosition = x;
        _yPosition = y;

        _parentDoWork?.Invoke();
    }

    public bool IsShown(int height, int width)
    {
        return _yPosition >= 0 && _yPosition < height && _xPosition >= 0 && _xPosition < width;
    }

    public int GetSize()
    {
        return _size;
    }
}
```
Класс `DesktopWindow`:
```C#
public class DesktopWindow : Window
{
    #region Fields

    private List<Shortcut> _shortcuts = new();
    private string _backgroundImagePath;

    #endregion



    public DesktopWindow(int width, int height, bool areAdministatorRightsGranted, string backgroundImagePath) : base(width, height, areAdministatorRightsGranted)
    {
        _backgroundImagePath = backgroundImagePath;
    }

    protected override void DoWork()
    {
        _memoryNeeded = _shortcuts.Where(sc => sc.IsShown(_height, _width)).Sum(sc => sc.GetSize());
    }


    public void AddShortcut(Shortcut shortcut)
    {
        shortcut.SetParentDoWork(DoWork);
        _shortcuts.Add(shortcut);
    }
}
```
Пример кода пользовательского приложения:
```C#
internal class Program
{
    private static Window Window { get; set; } = null!;
    static void Main()
    {
        var window = CreateWindow(800, 450, "./src/images/cat.jpg");
        ChangeWindow(window);

        var desktop = Window as DesktopWindow;
        desktop?.AddShortcut(new Shortcut(15, 200, 50, "./scr/icons/minecraft.ico"));
        Window.ShowOrHide(true);


        window = CreateWindow(800, 450, "./src/images/dog.jpg");
        ChangeWindow(window);

        desktop = Window as DesktopWindow;
        desktop?.AddShortcut(new Shortcut(15, 200, 50, "./scr/icons/minecraft.ico"));
        Window.ShowOrHide(true);
    }

    private static void ChangeWindow(Window window)
    {
        Window = window;
    }

    private static Window CreateWindow(int width, int height, string backgroundImagePath)
    {
        return new DesktopWindow(width, height, false, backgroundImagePath);
    }
}
```
