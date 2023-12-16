using Lab_07;


Queue<Rabota> rabota = new Queue<Rabota>();

string inp;
using (StreamReader reader = new StreamReader("../../../input.txt"))
{
    inp = reader.ReadToEnd();
}
string[] inputs = inp.Split(' ').Select(s => s.Split('-')).Aggregate((left, right) => [.. left, .. right]);

for (int i = 0; i < inputs.Length; i += 3)
{
    rabota.Enqueue(new Rabota(inputs[i], Convert.ToInt32(inputs[i + 1]), Convert.ToInt32(inputs[i + 2])));
}

Worker[] workers = new Worker[4]
{

    new Worker("w1", 100, rabota),
    new Worker("w2", 200, rabota),
    new Worker("w3", 300, rabota),
    new Worker("w4", 400, rabota),
};

foreach (var worker in workers)
{
    new Thread(worker.Work).Start();
}



namespace Lab_07
{
    class Rabota
    {
        public string Name;
        public int Num;
        public int Time;
        public int NowWork;

        public Rabota(string name, int num, int time)
        {
            Name = name;
            Num = num;
            Time = time;
            NowWork = 0;
        }
    }

    class Worker
    {
        private static Mutex mutex = new();

        public string Name;
        public int Power;
        private readonly Queue<Rabota> rabota;
        public Worker(string name, int power, Queue<Rabota> rabota)
        {
            Name = name;
            Power = power;
            this.rabota = rabota;
        }
        public void Work()
        {
            while (rabota.Count != 0)
            {
                mutex.WaitOne();
                if (rabota.Count != 0)
                {
                    Rabota rab = rabota.Peek();
                    rab.NowWork++;
                    if (rab.NowWork == rab.Num)
                    {
                        rabota.Dequeue();
                    }
                    mutex.ReleaseMutex();
                    bool temp = true;
                    while (rab.NowWork != rab.Num)
                    {
                        if (temp)
                        {
                            Console.WriteLine($"{Name} wait for work - {rab.Name}");
                            temp = false;
                        }

                    }

                    Mutex mutex1 = new Mutex();
                    mutex1.WaitOne();

                    Console.WriteLine($"{Name} start work - {rab.Name}");
                    Thread.Sleep(rab.Time / Power);
                    Console.WriteLine($"{Name} finish work - {rab.Name} - {rab.Time} - {rab.Time / Power}");
                    mutex1.ReleaseMutex();
                }
                else
                {
                    mutex.ReleaseMutex();
                    break;
                }
            }

        }
    }
}
