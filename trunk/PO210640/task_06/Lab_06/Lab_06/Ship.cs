namespace Lab_06;

public enum ShipType
{
    Carrier = 4,
    Battleship = 3,
    Cruiser = 2,
    Destroyer = 1
}

internal class Ship : ICloneable
{
    public ShipType ShipType { get; }
    public int Length => (int)ShipType;
    public bool[] Hits { get; }
    public bool IsSunk => Hits.All(x => x);

    public Ship(ShipType shipType)
    {
        ShipType = shipType;
        Hits = new bool[Length];
    }

    public object Clone()
    {
        var clone = new Ship(ShipType);
        Hits.CopyTo(clone.Hits, 0);

        return clone;
    }
}
