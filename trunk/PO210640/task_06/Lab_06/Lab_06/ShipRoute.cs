namespace Lab_06;

internal enum Orientation
{
    Left,
    Top,
    Right,
    Bottom,
}

internal class ShipRoute : ICloneable
{
    public Ship Ship { get; set; }
    public Point Start { get; set; }
    public Orientation Orientation { get; set; }

    public ShipRoute(Ship ship, Point start, Orientation orientation)
    {
        Ship = ship;
        Start = start;
        Orientation = orientation;
    }


    public void GetShot(Point point)
    {
        var (x, y) = point;
        var (startX, startY) = Start;

        var index = Orientation switch
        {
            Orientation.Left => startX - x,
            Orientation.Top => startY - y,
            Orientation.Right => x - startX,
            Orientation.Bottom => y - startY,
            _ => throw new NotImplementedException(),
        };

        Ship.Hits[index] = true;
    }

    public object Clone()
    {
        var ship = (Ship)Ship.Clone();
        var start = new Point(Start.X, Start.Y);
        var orientation = Orientation;

        return new ShipRoute(ship, start, orientation);
    }
}
