namespace Lab_06;

public enum CellState
{
    Empty,
    FogOfWar,
    Ship,
    HoloShip,
    IncorrectHoloShip,
    Hit,
    HoloHit,
    IncorrectHoloHit,
    Miss,
    Sunk,
    Clear,
}

internal static class CellStateExtension
{
    public static char ToSymbol(this CellState cellState)
    {
        return cellState switch
        {
            CellState.Empty => '~',
            CellState.FogOfWar => ' ',
            CellState.Ship => '■', // ∎
            CellState.HoloShip => '□',
            CellState.IncorrectHoloShip => '□',
            CellState.Hit => '☒',
            CellState.HoloHit => '◎',
            CellState.IncorrectHoloHit => '◎',
            CellState.Miss => '◉',
            CellState.Sunk => '☒',
            CellState.Clear => '*',
            _ => throw new NotImplementedException(),
        };
    }

    public static ConsoleColor ToColor(this CellState cellState)
    {
        return cellState switch
        {
            CellState.Empty => ConsoleColor.Blue,
            CellState.FogOfWar => ConsoleColor.Gray,
            CellState.Ship => ConsoleColor.Green,
            CellState.HoloShip => ConsoleColor.Cyan,
            CellState.IncorrectHoloShip => ConsoleColor.Red,
            CellState.Hit => ConsoleColor.Red,
            CellState.HoloHit => ConsoleColor.Cyan,
            CellState.IncorrectHoloHit => ConsoleColor.Red,
            CellState.Miss => ConsoleColor.DarkGray,
            CellState.Sunk => ConsoleColor.DarkRed,
            CellState.Clear => ConsoleColor.DarkBlue,
            _ => throw new NotImplementedException(),
        };
    }
}

internal abstract class Cell
{
    public bool IsHit { get; set; }
    public abstract CellState CellState { get; }
    public virtual void Shoot(Point point)
    {
        IsHit = true;
    }
}

internal class EmptyCell : Cell
{
    public bool IsClear { get; set; }
    public override CellState CellState
    {
        get
        {
            if (IsClear)
            {
                return CellState.Clear;
            }
            else
            {
                return IsHit ? CellState.Miss : CellState.Empty;
            }
        }
    }
}
internal class ShipCell : Cell
{
    public ShipRoute ShipRoute { get; init; }

    public bool IsSunk => ShipRoute.Ship.IsSunk;

    public ShipCell(ShipRoute shipRoute)
    {
        ShipRoute = shipRoute;
    }

    public override CellState CellState
    {
        get
        {
            if (IsSunk)
            {
                return CellState.Sunk;
            }
            else if (IsHit)
            {
                return CellState.Hit;
            }
            else
            {
                return CellState.Ship;
            }
        }
    }

    public override void Shoot(Point point)
    {
        base.Shoot(point);
        ShipRoute.GetShot(point);
    }
}


internal abstract class HoloCell : Cell
{
    protected HoloCell(CellState cellState)
    {
        _cellState = cellState;
    }

    protected readonly CellState _cellState;
    public override CellState CellState => _cellState;

}
internal class HoloShipCell : HoloCell
{
    public ShipRoute ShipRoute { get; init; }

    public HoloShipCell(ShipRoute shipRoute, CellState cellState) : base(cellState)
    {
        ShipRoute = shipRoute;
    }
}

internal class HoloShotCell : HoloCell
{
    public HoloShotCell(CellState cellState) : base(cellState)
    {
    }
}

