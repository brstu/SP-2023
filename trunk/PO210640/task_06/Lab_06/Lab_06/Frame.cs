using System.Text;

namespace Lab_06;



internal class Frame
{
    public int Length { get; init; }
    public int Width { get; init; }

    public Point Offset { get; init; }

    private char[] Elements { get; init; }
    private string _frameStr = string.Empty;
    private string FrameStr
    {
        get
        {
            if (_frameStr == string.Empty)
            {
                _frameStr = GetFrame();
            }

            return _frameStr;
        }
    }

    public char LeftBottom => Elements[0];
    public char LeftTop => Elements[1];
    public char RightTop => Elements[2];
    public char RightBottom => Elements[3];
    public char Horizontal => Elements[4];
    public char Vertical => Elements[5];

    public Frame(int length, int width)
    {
        Length = length;
        Width = width;

        var xOffset = Length.ToString().Length + 2;
        var yOffset = 2;
        Offset = new Point(xOffset, yOffset);

        Elements = ['╚', '╔', '╗', '╝', '═', '║'];
    }

    private string GetFrame()
    {
        var sb = new StringBuilder();

        var paddingLentgh = Length.ToString().Length;
        var padding = new string(' ', paddingLentgh + 1);


        // Top
        sb.Append(padding);
        for (char ch = 'A'; ch < 'A' + Width; ch++)
        {
            sb.Append(' ');
            sb.Append(ch);
        }
        sb.AppendLine();

        var topLine = padding + LeftTop + new string(Horizontal, Width * 2 - 1) + RightTop;
        sb.AppendLine(topLine);

        // Middle
        var midLine = Vertical + new string(' ', Width * 2 - 1) + Vertical;
        for (int i = 0; i < Length; i++)
        {
            var temp = (i + 1).ToString().PadLeft(paddingLentgh) + ' ' + midLine;
            sb.AppendLine(temp);
        }

        // Bottom
        var bottomLine = padding + LeftBottom + new string(Horizontal, Width * 2 - 1) + RightBottom;
        sb.AppendLine(bottomLine);

        return sb.ToString();
    }

    private static void NextLine(int left)
    {
        var (_, Top) = Console.GetCursorPosition();
        Console.SetCursorPosition(left, Top + 1);
    }


    public void Draw(int left, int top)
    {
        var paddingLentgh = Length.ToString().Length;
        var padding = new string(' ', paddingLentgh + 1);


        // Top
        Console.SetCursorPosition(left, top);
        Console.Write(padding);
        for (char ch = 'A'; ch < 'A' + Width; ch++)
        {
            Console.Write(' ');
            Console.Write(ch);
        }
        NextLine(left);

        var topLine = padding + LeftTop + new string(Horizontal, Width * 2 - 1) + RightTop;
        Console.Write(topLine);
        NextLine(left);

        // Middle
        var midLine = Vertical + new string(' ', Width * 2 - 1) + Vertical;
        for (int i = 0; i < Length; i++)
        {
            var temp = (i + 1).ToString().PadLeft(paddingLentgh) + ' ' + midLine;
            Console.Write(temp);
            NextLine(left);
        }

        // Bottom
        var bottomLine = padding + LeftBottom + new string(Horizontal, Width * 2 - 1) + RightBottom;
        Console.Write(bottomLine);
        NextLine(left);
    }


    public override string ToString()
    {
        return FrameStr;
    }
}
