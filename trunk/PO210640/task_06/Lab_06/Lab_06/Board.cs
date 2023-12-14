namespace Lab_06;


internal class Board
{
    public int Height { get; init; }
    public int Width { get; init; }

    public bool End => ShipRoutes.All(x => x.Ship.IsSunk);

    private List<ShipRoute> ShipRoutes { get; init; }

    private Cell[,] Cells { get; init; }
    private Cell[,] HoloCells { get; init; }
    private bool IsAddingHolo { get; set; }

    private Frame Frame { get; init; }

    public Board(int height, int width)
    {
        Height = height;
        Width = width;

        Frame = new Frame(Height, Width);

        ShipRoutes = [];

        Cells = new Cell[Height, Width];
        HoloCells = new Cell[Height, Width];
        for (int i = 0; i < Height; i++)
        {
            for (int j = 0; j < Width; j++)
            {
                Cells[i, j] = new EmptyCell();
                HoloCells[i, j] = new EmptyCell();
            }
        }
    }


    public void AddShip(Ship ship, Point start, Orientation orientation)
    {
        var shipRoute = new ShipRoute(ship, start, orientation);
        ShipRoutes.Add(shipRoute);

        var (x, y) = start;
        for (int i = 0; i < ship.Length; i++)
        {
            Cells[y, x] = new ShipCell(shipRoute);

            switch (orientation)
            {
                case Orientation.Left:
                    x--;
                    break;

                case Orientation.Top:
                    y--;
                    break;

                case Orientation.Right:
                    x++;
                    break;

                case Orientation.Bottom:
                    y++;
                    break;
            }
        }
    }




    public bool MoveHoloShip(ShipRoute shipRoute, ShipRoute? prevShipRoute = null)
    {
        if (IsAddingHolo && prevShipRoute is null)
        {
            throw new Exception("Cannot add holo ship when adding holo");
        }

        if (prevShipRoute is not null)
        {
            RemoveHoloShip(prevShipRoute);
        }

        var canAddShip = AddHoloShip(shipRoute);
        return canAddShip;
    }

    private bool AddHoloShip(ShipRoute shipRoute)
    {
        var ship = shipRoute.Ship;
        var start = shipRoute.Start;
        var orientation = shipRoute.Orientation;

        bool canAddShip = CanAddShip(shipRoute);
        var cellState = canAddShip ? CellState.HoloShip : CellState.IncorrectHoloShip;

        var (x, y) = start;
        for (int i = 0; i < ship.Length; i++)
        {
            y = (y + Height) % Height;
            x = (x + Width) % Width;
            HoloCells[y, x] = new HoloShipCell(shipRoute, cellState);

            switch (orientation)
            {
                case Orientation.Left:
                    x--;
                    break;

                case Orientation.Top:
                    y--;
                    break;

                case Orientation.Right:
                    x++;
                    break;

                case Orientation.Bottom:
                    y++;
                    break;
            }
        }

        IsAddingHolo = true;
        return canAddShip;
    }

    private bool CanAddShip(ShipRoute shipRoute)
    {
        var start = shipRoute.Start;
        var orientation = shipRoute.Orientation;
        var lengthShip = shipRoute.Ship.Length;

        var topLeft = orientation switch
        {
            Orientation.Left => new Point(start.X - lengthShip, start.Y - 1),
            Orientation.Top => new Point(start.X - 1, start.Y - lengthShip),
            Orientation.Right => new Point(start.X - 1, start.Y - 1),
            Orientation.Bottom => new Point(start.X - 1, start.Y - 1),
            _ => throw new NotImplementedException(),
        };

        var bottomRight = orientation switch
        {
            Orientation.Left => new Point(start.X + 1, start.Y + 1),
            Orientation.Top => new Point(start.X + 1, start.Y + 1),
            Orientation.Right => new Point(start.X + lengthShip, start.Y + 1),
            Orientation.Bottom => new Point(start.X + 1, start.Y + lengthShip),
            _ => throw new NotImplementedException(),
        };

        var (xShip, yShip) = start;
        for (int i = 0; i < lengthShip; i++)
        {
            if (yShip < 0 || yShip >= Height || xShip < 0 || xShip >= Width)
            {
                return false;
            }

            switch (orientation)
            {
                case Orientation.Left:
                    xShip--;
                    break;

                case Orientation.Top:
                    yShip--;
                    break;

                case Orientation.Right:
                    xShip++;
                    break;

                case Orientation.Bottom:
                    yShip++;
                    break;
            }
        }

        var height = Height;
        var width = Width;

        for (int y = topLeft.Y; y <= bottomRight.Y; y++)
        {
            for (int x = topLeft.X; x <= bottomRight.X; x++)
            {
                if (y >= 0 && y < height && x >= 0 && x < width)
                {
                    if (Cells[y, x] is not EmptyCell)
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }

    public void RemoveHoloShip(ShipRoute shipRoute)
    {
        var ship = shipRoute.Ship;
        var start = shipRoute.Start;
        var orientation = shipRoute.Orientation;

        var (x, y) = start;
        for (int i = 0; i < ship.Length; i++)
        {
            y = (y + Height) % Height;
            x = (x + Width) % Width;
            HoloCells[y, x] = new EmptyCell();

            switch (orientation)
            {
                case Orientation.Left:
                    x--;
                    break;

                case Orientation.Top:
                    y--;
                    break;

                case Orientation.Right:
                    x++;
                    break;

                case Orientation.Bottom:
                    y++;
                    break;
            }
        }

        IsAddingHolo = false;
    }

    public void SubmitHoloShip(ShipRoute shipRoute)
    {
        var ship = shipRoute.Ship;
        var start = shipRoute.Start;
        var orientation = shipRoute.Orientation;

        var (x, y) = start;

        if (HoloCells[y, x] is not HoloShipCell holoShip || holoShip.ShipRoute != shipRoute)
        {
            throw new Exception("Can't sumbit adding non-existent ship");
        }

        for (int i = 0; i < ship.Length; i++)
        {
            Cells[y, x] = new ShipCell(shipRoute);

            switch (orientation)
            {
                case Orientation.Left:
                    x--;
                    break;

                case Orientation.Top:
                    y--;
                    break;

                case Orientation.Right:
                    x++;
                    break;

                case Orientation.Bottom:
                    y++;
                    break;
            }
        }

        ShipRoutes.Add(shipRoute);
    }





    private bool Shoot(Point point)
    {
        var isValid = true;

        var (x, y) = point;
        var cell = Cells[y, x];

        if (cell.IsHit)
        {
            return !isValid;
        }

        cell.Shoot(point);

        if (cell is ShipCell shipCell && shipCell.IsSunk)
        {
            Sink(shipCell.ShipRoute);
        }

        return isValid;
    }
    private bool AddHoloShot(Point point)
    {
        var x = point.X;
        var y = point.Y;
        var cell = Cells[y, x];

        bool isPossible = cell.IsHit == false;
        var cellState = isPossible ? CellState.HoloHit : CellState.IncorrectHoloHit;

        HoloCells[y, x] = new HoloShotCell(cellState);

        return isPossible;
    }

    public void RemoveHoloShot(Point point)
    {
        var x = point.X;
        var y = point.Y;

        HoloCells[y, x] = new EmptyCell();
    }

    public bool MoveHoloShot(Point current, Point? prev = null)
    {
        if (IsAddingHolo && prev is null)
        {
            throw new Exception("Cannot add holo ship when adding holo");
        }

        if (prev is not null)
        {
            RemoveHoloShot(prev.Value);
        }

        var canShoot = AddHoloShot(current);
        return canShoot;
    }

    public bool SubmitHoloShot(Point point)
    {
        var (x, y) = point;
        var cell = Cells[y, x];

        bool isHit = false;

        if (cell.CellState is CellState.Ship)
        {
            isHit = true;
        }

        Shoot(point);

        return isHit;
    }

    private void Sink(ShipRoute shipRoute)
    {
        var start = shipRoute.Start;
        var orientation = shipRoute.Orientation;
        var lengthShip = shipRoute.Ship.Length;

        var topLeft = orientation switch
        {
            Orientation.Left => new Point(start.X - lengthShip, start.Y - 1),
            Orientation.Top => new Point(start.X - 1, start.Y - lengthShip),
            Orientation.Right => new Point(start.X - 1, start.Y - 1),
            Orientation.Bottom => new Point(start.X - 1, start.Y - 1),
            _ => throw new NotImplementedException(),
        };

        var bottomRight = orientation switch
        {
            Orientation.Left => new Point(start.X + 1, start.Y + 1),
            Orientation.Top => new Point(start.X + 1, start.Y + 1),
            Orientation.Right => new Point(start.X + lengthShip, start.Y + 1),
            Orientation.Bottom => new Point(start.X + 1, start.Y + lengthShip),
            _ => throw new NotImplementedException(),
        };

        var height = Height;
        var width = Width;

        for (int y = topLeft.Y; y <= bottomRight.Y; y++)
        {
            for (int x = topLeft.X; x <= bottomRight.X; x++)
            {
                if (y >= 0 && y < height && x >= 0 && x < width)
                {
                    if (Cells[y, x] is EmptyCell emptyCell && emptyCell.IsHit == false)
                    {
                        emptyCell.IsClear = true;
                        emptyCell.IsHit = true;
                    }
                }
            }
        }
    }







    public void Draw(int left, int top)
    {
        Frame.Draw(left, top);

        var height = Height;
        var width = Width;

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                var cell = Cells[i, j];
                var cellState = cell.CellState;
                var symbol = cellState.ToSymbol();
                var color = cellState.ToColor();

                Console.SetCursorPosition(Frame.Offset.X + left + j * 2, Frame.Offset.Y + top + i);
                Console.ForegroundColor = color;
                Console.Write(symbol);
            }
        }

        //Console.BackgroundColor = Constants.DefaultBackground;
        Console.ForegroundColor = Constants.DefaultForeground;
    }

    public void DrawFogged(int left, int top)
    {
        Frame.Draw(left, top);

        var height = Height;
        var width = Width;

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                var cell = Cells[i, j];
                var cellState = cell.CellState;
                if (cellState is CellState.Ship or CellState.Empty)
                {
                    cellState = CellState.FogOfWar;
                }
                var symbol = cellState.ToSymbol();
                var color = cellState.ToColor();

                Console.SetCursorPosition(Frame.Offset.X + left + j * 2, Frame.Offset.Y + top + i);
                Console.ForegroundColor = color;
                Console.Write(symbol);
            }
        }

        //Console.BackgroundColor = Constants.DefaultBackground;
        Console.ForegroundColor = Constants.DefaultForeground;
    }

    public void DrawHolo(int left, int top)
    {
        var height = Height;
        var width = Width;

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                var cell = HoloCells[i, j];

                if (cell is EmptyCell)
                {
                    continue;
                }

                var cellState = cell.CellState;
                var symbol = cellState.ToSymbol();
                var color = cellState.ToColor();

                Console.SetCursorPosition(Frame.Offset.X + left + j * 2, Frame.Offset.Y + top + i);
                Console.ForegroundColor = color;
                Console.Write(symbol);
            }
        }

        //Console.BackgroundColor = Constants.DefaultBackground;
        Console.ForegroundColor = Constants.DefaultForeground;
    }
}
