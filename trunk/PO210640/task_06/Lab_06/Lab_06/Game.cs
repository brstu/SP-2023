namespace Lab_06;

internal class Game
{
    public int Width { get;}
    public int Height { get; }

    private Player Player1 { get; }
    private Player Player2 { get; }


    public Game(int height, int width)
    {
        var (name1, name2) = GetNames();

        if (string.IsNullOrWhiteSpace(name1))
        {
            name1 = "Player 1";
        }

        if (string.IsNullOrWhiteSpace(name2))
        {
            name2 = "Player 2";
        }

        Player1 = new Player(name1, new Board(height, width));

        if (name2 == "Bot")
        {
            Player2 = new Bot(name2, new Board(height, width));
        }
        else
        {
            Player2 = new Player(name2, new Board(height, width));
        }

        

        Width = width;
        Height = height;
    }

    private void SetShips()
    {
        Console.WriteLine($"Player {Player1.Name} creating fleet. Press any key to continue...");
        Console.ReadKey(true);
        Console.Clear();

        CreateFleet(Player1);
        Console.Clear();


        if (Player2 is Bot bot)
        {
            bot.CreateFleet();
            Console.Clear();
        }
        else
        {

            Console.WriteLine($"Player {Player2.Name} creating fleet. Press any key to continue...");
            Console.ReadKey(true);
            Console.Clear();

            CreateFleet(Player2);
            Console.Clear();
        }
    }












    private static (string?, string?) GetNames()
    {
        Console.CursorVisible = true;
        Console.Write("Enter first player`s name: ");
        var name1 = Console.ReadLine();

        Console.WriteLine();
        Console.WriteLine("Enter \"Bot\" to play against computer");
        Console.Write("Enter second player`s name: ");
        var name2 = Console.ReadLine();

        Console.CursorVisible = false;
        Console.Clear();

        return (name1, name2);
    }

    private void CreateFleet(Player player)
    {
        // default settings
        var shipTypes = new Dictionary<ShipType, int>();
        var count = Enum.GetValues<ShipType>().Length;
        Enum.GetValues<ShipType>().ToList().ForEach(x => shipTypes.Add(x, count + 1 - (int)x));

        var start = new Point(0, 0);
        while (shipTypes.Any(x => x.Value > 0))
        {
            var availableShipTypes = shipTypes.Where(x => x.Value > 0).Select(x => x.Key).ToList();
            var addedShipRoute = AddShipRoute(player.Board, availableShipTypes, start, new(0, 0));
            if (addedShipRoute is not null)
            {
                shipTypes[addedShipRoute.Ship.ShipType]--;
                start = addedShipRoute.Start;
            }
        }
    }

    private ShipRoute? AddShipRoute(Board board, List<ShipType> shipTypes, Point start, Point position)
    {
        var shipTypeIndex = shipTypes.Count - 1;
        var shipType = shipTypes[shipTypeIndex];

        List<Orientation> orientations = [];
        Enum.GetValues<Orientation>().ToList().ForEach(orientations.Add);

        var orientationIndex = (int)Orientation.Right;
        var orientation = orientations[orientationIndex];

        var startPoint = start;

        var currentShipRoute = new ShipRoute(new Ship(shipType), startPoint, orientation);
        ShipRoute? prevShipRoute = null;

        bool isCorrect = board.MoveHoloShip(currentShipRoute, prevShipRoute);

        var (left, top) = position;

        while (true)
        {
            board.Draw(left, top);
            board.DrawHolo(left, top);


            var keyinfo = Console.ReadKey(true);
            var key = keyinfo.Key;


            if (key is ConsoleKey.Enter && isCorrect)
            {
                board.SubmitHoloShip(currentShipRoute);
                board.RemoveHoloShip(currentShipRoute);
                return currentShipRoute;
            }

            if (key is ConsoleKey.Escape)
            {
                board.RemoveHoloShip(currentShipRoute);
                return null;
            }

            int coef = keyinfo.Modifiers.HasFlag(ConsoleModifiers.Shift) ? -1 : 1;

            if (key is ConsoleKey.Tab)
            {
                shipTypeIndex += coef;
            }

            shipTypeIndex = (shipTypeIndex + shipTypes.Count) % shipTypes.Count;
            shipType = shipTypes[shipTypeIndex];

            if (key is ConsoleKey.R)
            {
                orientationIndex += coef;
            }

            orientationIndex = (orientationIndex + orientations.Count) % orientations.Count;
            orientation = orientations[orientationIndex];


            startPoint = key switch
            {
                ConsoleKey.UpArrow => new Point(startPoint.X, startPoint.Y - 1),
                ConsoleKey.W => new Point(startPoint.X, startPoint.Y - 1),

                ConsoleKey.DownArrow => new Point(startPoint.X, startPoint.Y + 1),
                ConsoleKey.S => new Point(startPoint.X, startPoint.Y + 1),

                ConsoleKey.LeftArrow => new Point(startPoint.X - 1, startPoint.Y),
                ConsoleKey.A => new Point(startPoint.X - 1, startPoint.Y),

                ConsoleKey.RightArrow => new Point(startPoint.X + 1, startPoint.Y),
                ConsoleKey.D => new Point(startPoint.X + 1, startPoint.Y),

                _ => startPoint,
            };

            startPoint.X = (startPoint.X + Width) % Width;
            startPoint.Y = (startPoint.Y + Height) % Height;


            prevShipRoute = currentShipRoute;
            currentShipRoute = new ShipRoute(new Ship(shipType), startPoint, orientation);


            isCorrect = board.MoveHoloShip(currentShipRoute, prevShipRoute);
        }
    }

    private bool? Shoot(Board board, ref Point start, Point position)
    {
        var currentShot = start;
        Point? prevShot = null;

        bool isCorrect = board.MoveHoloShot(currentShot, prevShot);

        var (left, top) = position;

        while (true)
        {
            board.DrawFogged(left, top);
            board.DrawHolo(left, top);

            var keyinfo = Console.ReadKey(true);
            var key = keyinfo.Key;


            if (key is ConsoleKey.Enter && isCorrect)
            {
                bool isHit = board.SubmitHoloShot(currentShot);
                board.RemoveHoloShot(currentShot);
                start = currentShot;
                return isHit;
            }

            if (key is ConsoleKey.Escape)
            {
                board.RemoveHoloShot(currentShot);
            }

            prevShot = currentShot;

            var (x, y) = currentShot;
            currentShot = key switch
            {
                ConsoleKey.UpArrow => new Point(x, y - 1),
                ConsoleKey.W => new Point(x, y - 1),

                ConsoleKey.DownArrow => new Point(x, y + 1),
                ConsoleKey.S => new Point(x, y + 1),

                ConsoleKey.LeftArrow => new Point(x - 1, y),
                ConsoleKey.A => new Point(x - 1, y),

                ConsoleKey.RightArrow => new Point(x + 1, y),
                ConsoleKey.D => new Point(x + 1, y),

                _ => currentShot,
            };

            currentShot.X = (currentShot.X + Width) % Width;
            currentShot.Y = (currentShot.Y + Height) % Height;

            isCorrect = board.MoveHoloShot(currentShot, prevShot);
        }
    }


    private void DrawFogged(Player playerActive)
    {
        Console.Clear();

        var (left, top) = (5, 2);

        Console.SetCursorPosition(left, top - 2);
        Console.ForegroundColor = (playerActive == Player1) ? ConsoleColor.Green : ConsoleColor.Gray;
        Console.Write($"Player {Player1.Name}");

        var widthOffset = Player1.Board.Width * 2 + 10;

        Console.SetCursorPosition(widthOffset + left, top - 2);
        Console.ForegroundColor = (playerActive == Player2) ? ConsoleColor.Green : ConsoleColor.Gray;
        Console.Write($"Player {Player2.Name}");

        Console.ForegroundColor = Constants.DefaultForeground;

        Player1.Board.DrawFogged(left, top);
        Player2.Board.DrawFogged(widthOffset + left, top);
    }

    private void DrawWinner(Player winner)
    {
        Console.Clear();

        var (left, top) = (5, 2);

        Console.SetCursorPosition(left, top - 2);
        Console.ForegroundColor = (winner == Player1) ? ConsoleColor.Yellow : ConsoleColor.DarkGray;
        var str1 = (winner == Player1) ? $"Winner {Player1.Name}" : $"Loser {Player1.Name}";
        Console.Write(str1);

        var widthOffset = Player1.Board.Width * 2 + 10;

        Console.SetCursorPosition(widthOffset + left, top - 2);
        Console.ForegroundColor = (winner == Player2) ? ConsoleColor.Yellow : ConsoleColor.DarkGray;
        var str2 = (winner == Player2) ? $"Winner {Player2.Name}" : $"Loser {Player2.Name}";
        Console.Write(str2);

        Console.ForegroundColor = Constants.DefaultForeground;

        Player1.Board.Draw(left, top);
        Player2.Board.Draw(widthOffset + left, top);
    }

    public void Start()
    {
        SetShips();

        var (left, top) = (5, 2);
        DrawFogged(Player1);

        var prevShot1 = new Point(0, 0);
        var prevShot2 = new Point(0, 0);

        var currentPlayer = Player1;
        var anotherPlayer = Player2;

        var offset1 = new Point(left, top);
        var offset2 = new Point(Width * 2 + 10 + left, top);

        while (!Player1.Board.End && !Player2.Board.End)
        {
            bool? isHit = null;
            var prevShot = currentPlayer == Player1 ? ref prevShot1 : ref prevShot2;
            var offset = currentPlayer == Player1 ? offset2 : offset1;

            while ((isHit is null || isHit.Value is true) && !anotherPlayer.Board.End)
            {
                if (currentPlayer is Bot bot)
                {
                    Thread.Sleep(500);
                    isHit = Bot.Shoot(anotherPlayer);
                    DrawFogged(currentPlayer);
                }
                else
                {
                    isHit = Shoot(anotherPlayer.Board, ref prevShot, offset);
                }
            }

            if (currentPlayer == Player1)
            {
                prevShot1 = prevShot;
            }
            else
            {
                prevShot2 = prevShot;
            }

            (currentPlayer, anotherPlayer) = (anotherPlayer, currentPlayer);
            DrawFogged(currentPlayer);
        }

        var loser = currentPlayer;
        var winner = loser == Player1 ? Player2 : Player1;

        Console.Clear();
        DrawWinner(winner);

        Console.ReadKey(true);
        Console.Clear();
    }

    private Player ChangePlayer(Player currentPlayer)
    {
        return (currentPlayer == Player1 ? Player2 : Player1);
    }
}
