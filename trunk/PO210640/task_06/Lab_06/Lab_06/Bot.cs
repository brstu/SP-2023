using System.Numerics;

namespace Lab_06;

internal class Bot : Player
{
    public Bot(string name, Board board) : base(name, board)
    {
    }

    public static bool Shoot(Player player)
    {
        var board = player.Board;

        var height = board.Height;
        var width = board.Width;

        var arr = new Point[height * width];
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                arr[i * width + j] = new Point(i, j);
            }
        }

        Random.Shared.Shuffle(arr);

        Point? prevPoint = null;
        foreach (var point in arr)
        {
            if (board.MoveHoloShot(point, prevPoint))
            {
                var isHit = board.SubmitHoloShot(point);
                board.RemoveHoloShot(point);
                return isHit;
            }

            prevPoint = point;
        }

        return false;
    }

    public void CreateFleet()
    {
        // default settings
        var shipTypes = new Dictionary<ShipType, int>();
        var count = Enum.GetValues<ShipType>().Length;
        Enum.GetValues<ShipType>().ToList().ForEach(x => shipTypes.Add(x, count + 1 - (int)x));

        var start = new Point(0, 0);

        var random = new Random();

        var height = Board.Height;
        var width = Board.Width;

        var arr = new Point[height * width];
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                arr[i * width + j] = new Point(i, j);
            }
        }

        while (shipTypes.Any(x => x.Value > 0))
        {
            var availableShipTypes = shipTypes.Where(x => x.Value > 0).Select(x => x.Key).ToArray();

            var type = random.GetItems(availableShipTypes, 1)[0];

            var orientation = random.GetItems(Enum.GetValues<Orientation>(), 1)[0];



            random.Shuffle(arr);

            var route = new ShipRoute(new Ship(type), arr[0], orientation);
            ShipRoute? prevRoute = null;

            foreach (var point in arr)
            {
                if (Board.MoveHoloShip(route, prevRoute))
                {
                    Board.SubmitHoloShip(route);
                    Board.RemoveHoloShip(route);

                    shipTypes[route.Ship.ShipType]--;

                    break;
                }

                prevRoute = route;
                route = new ShipRoute(new Ship(type), point, orientation);
            }
        }
    }
}
