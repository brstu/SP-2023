namespace Lab_07;

internal static class Program
{
    private static Mutex Mutex { get; set; } = new();
    private static Queue<string> Tasks { get; set; } = new();

    private static int Id { get; set; } = 1;

    private static bool IsEnd { get; set; }

    static void Main()
    {
        for (int i = 0; i < 10; i++)
        {
            Tasks.Enqueue($"Task {i + 1}");
        }

        for (int i = 0; i < 4; i++)
        {
            new Thread(Operator).Start();
        }

        int taskId = 11;
        while (!IsEnd)
        {
            if (taskId == 100)
            {
                IsEnd = true;
                return;
            }

            Thread.Sleep(Random.Shared.Next(500));

            Mutex.WaitOne();
            Tasks.Enqueue($"Task {taskId++}");
            Mutex.ReleaseMutex();
        }
    }

    private static void Operator()
    {
        Mutex.WaitOne();
        var id = Id++;
        Mutex.ReleaseMutex();
        string task;
        while (!IsEnd)
        {
            Mutex.WaitOne();
            while (!Tasks.TryDequeue(out task))
            {
                Mutex.ReleaseMutex();
                Thread.Sleep(50);
                Mutex.WaitOne();
            }
            Console.BackgroundColor = ConsoleColor.Magenta;
            Console.Write($"Operator {id} - took {task} - {DateTime.Now.TimeOfDay}");
            Console.ResetColor();
            Console.WriteLine();
            Mutex.ReleaseMutex();

            var time = Random.Shared.Next(1000, 10000);
            Thread.Sleep(time);
            Console.WriteLine($"Operator {id} - completed {task} - {time} ms");
        }
    }
}
