using System.Text;

namespace Lab_06;

internal class Program
{
    static void Main()
    {
        Console.OutputEncoding = Encoding.UTF8;
        Console.ForegroundColor = Constants.DefaultForeground;
        Console.CursorVisible = false;
        Console.Title = "Battleship Game";

        var game = new Game(10, 10);
        game.Start();
    }
}
