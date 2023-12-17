using ClassLibrary1;

Item item1 = new Item(1,100,200,200,10);
Item item2 = new Item(2,2399,100,100,50);
Item item3 = new Item(3,9999,1000,200,190);

item1.ShowInfo();
Console.WriteLine($"Cost for weight: {item1.CostForWeight()}\n" +
                  $"Time of life: {item1.TimeOfLife()}");
item2.ShowInfo();
Console.WriteLine($"Cost for weight: {item2.CostForWeight()}\n" +
                  $"Time of life: {item2.TimeOfLife()}");
item3.ShowInfo();
Console.WriteLine($"Cost for weight: {item3.CostForWeight()}\n" +
                  $"Time of life: {item3.TimeOfLife()}");