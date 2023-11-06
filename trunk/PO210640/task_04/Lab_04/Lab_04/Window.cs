namespace Lab_04;

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
