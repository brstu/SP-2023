namespace Lab_04;

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