
#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>

std::mutex mtx;
std::atomic<int> counter{ 0 };


int main()
{
    int times1, inc1, dec1, mult1;
    int times, inc, dec, mult;
    int num = 0;

    setlocale(LC_ALL, "russian");
    int value = 0;
    while (value != 3)
    {
        std::cout << "1. Выполнить через мьютексы" << std::endl;
        std::cout << "2. Выполнить через atomic" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cin >> value;

        switch (value)
        {
        case 1:
        {
            std::cout << "Введите количество итераций: ";
            std::cin >> times;
            std::cout << "Введите значение для увеличения: ";
            std::cin >> inc;
            std::cout << "Введите значение для уменьшения: ";
            std::cin >> dec;
            std::cout << "Введите значение для умножения: ";
            std::cin >> mult;

            std::thread t1([&]() {
                for (int i = 0; i < times; ++i) {
                    mtx.lock();
                    num += inc;
                    mtx.unlock();
                }
                });

            std::thread t2([&]() {
                for (int i = 0; i < times; ++i) {
                    mtx.lock();
                    num -= dec;
                    mtx.unlock();
                }
                });

            std::thread t3([&]() {
                for (int i = 0; i < times; ++i) {
                    mtx.lock();
                    num *= mult;
                    mtx.unlock();
                }
                });

            t1.join();
            t2.join();
            t3.join();
            std::cout << "Результат: " << num << std::endl;

        }
        break;

        case 2:
        {

            std::cout << "Введите количество итераций: ";
            std::cin >> times1;
            std::cout << "Введите значение для увеличения: ";
            std::cin >> inc1;
            std::cout << "Введите значение для уменьшения: ";
            std::cin >> dec1;
            std::cout << "Введите значение для умножения: ";
            std::cin >> mult1;


            std::thread t4([&]() {
                for (int i = 0; i < times; ++i) {
                    counter.fetch_add(inc1, std::memory_order_relaxed);
                }
                });

            std::thread t5([&]() {
                for (int i = 0; i < times; ++i) {
                    counter.fetch_sub(dec1, std::memory_order_relaxed);
                }
                });

            std::thread t6([&]() {
                for (int i = 0; i < times; ++i) {
                    //   counter.fetch_mul(mult, std::memory_order_relaxed);
                    mult1 = counter.load() * mult1;
                    counter.store(counter);
                }
                });

            t4.join();
            t5.join();
            t6.join();

            std::cout << "Результат: " << counter << std::endl;

        }
        break;
        default:
            std::cout << "Не балуйся и выбирай то, что нужно" << std::endl;
            break;
        }


    }
    return 0;
}