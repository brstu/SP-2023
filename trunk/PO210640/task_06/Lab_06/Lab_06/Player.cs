namespace Lab_06;

internal class Player
{
    public string Name { get; }
    public int Score { get; private set; }

    public Board Board { get; }


    public Player(string name, Board board)
    {
        Name = name;
        Score = 0;

        Board = board;
    }

    public void AddScore(int score)
    {
        Score += score;
    }
}
