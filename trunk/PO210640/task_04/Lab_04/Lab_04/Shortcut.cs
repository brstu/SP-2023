using System.Diagnostics;

namespace Lab_04;

public class Shortcut
{
    #region Fields

    private static int _nextId;

    private readonly int _id;
    private readonly int _size;
    private int _xPosition;
    private int _yPosition;
    private readonly string _path;

    private Action? _parentDoWork = null;

    #endregion

    public Shortcut(int size, int xPosition, int yPosition, string path)
    {
        _id = GetNextId();

        _size = size;
        _xPosition = xPosition;
        _yPosition = yPosition;
        _path = path;
    }

    private static int GetNextId()
    {
        return _nextId++;
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
