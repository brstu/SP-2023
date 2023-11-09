namespace Lab_04;

public class DesktopWindow : Window
{
    #region Fields

    private readonly List<Shortcut> _shortcuts = new();
    private readonly string _backgroundImagePath;

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
