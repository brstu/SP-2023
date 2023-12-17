namespace ClassLibrary1;

public class Item
{
    private int _id;
    private decimal _cost;
    private int _weight;
    private int _durability;
    private int _age;

    public Item(int id, decimal cost, int weight, int durability, int age)
    {
        _id = id;
        _cost = cost;
        _weight = weight;
        _durability = durability;
        _age = age;
    }

    public decimal CostForWeight()
    {
        return _weight / _cost;
    }

    public int TimeOfLife()
    {
        return _durability - _age;
    }

    public void ShowInfo()
    {
        Console.WriteLine($"Id: {_id}\n" +
                          $"Cost: {_cost}\n" +
                          $"Weight: {_weight}\n" +
                          $"Durability: {_durability}\n" +
                          $"Age: {_age}");
    }
}