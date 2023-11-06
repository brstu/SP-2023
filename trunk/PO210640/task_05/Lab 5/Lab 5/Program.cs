namespace Lab_5;

public class Program
{
    static void Main()
    {
        float valueAtomic = 10.0f;

        Action GetIncreaseMethodAtomic(float percent)
        {
            return () =>
            {
                var coef = 1.0f + percent / 100.0f;
                var temp = Interlocked.Exchange(ref valueAtomic, 0);
                temp *= coef;
                Interlocked.Exchange(ref valueAtomic, temp);
            };
        }

        float valueMutex = 10.0f;

        Mutex mutex = new();
        Action GetIncreaseMethodMutex(float percent)
        {
            return () =>
            {
                var coef = 1.0f + percent / 100.0f;
                mutex.WaitOne();
                valueMutex *= coef;
                mutex.ReleaseMutex();
            };
        }

        var lambda = (Func<float, Action> func) =>
        {
            float[] percents = { 5.0f, 25.0f, 15.0f, 35.0f, };

            var methodList = new List<Action>();
            foreach (var coef in percents)
            {
                methodList.Add(func(coef));
            }

            IEnumerable<Action> GetActions()
            {
                foreach (var method in methodList)
                {
                    yield return method;
                }

                foreach (var method in methodList)
                {
                    yield return method;
                }
            }

            return GetActions();
        };

        var methodsAtomic = lambda(GetIncreaseMethodAtomic).GetEnumerator();

        var threadAtomic = new Thread(() => { NextThread(methodsAtomic); });
        threadAtomic.Start();
        threadAtomic.Join();

        Console.Write("Atomic: ");
        Console.WriteLine(valueAtomic);

        var methodsMutex = lambda(GetIncreaseMethodMutex).GetEnumerator();

        var threadMutex = new Thread(() => { NextThread(methodsMutex); });
        threadMutex.Start();
        threadMutex.Join();


        Console.Write("Mutex: ");
        Console.WriteLine(valueMutex);
    }

    private static void NextThread(IEnumerator<Action> methods)
    {
        if (!methods.MoveNext()) return;

        methods.Current.Invoke();

        var thread = new Thread(() => { NextThread(methods); });
        thread.Start();
        thread.Join();
    }
}