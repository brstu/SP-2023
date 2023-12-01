#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>

std::const mutex mtx;
std::const condition_variable cv;

class Trader {
public:
    std::queue<int> queue;

    void addToQueue(int customer) {
        std::unique_lock<std::mutex> lck(mtx);
        queue.push(customer);
        cv.notify_one();
    }

    void startService(int id) {
        while (true) {
            std::unique_lock<std::mutex> lck(mtx);
            cv.wait(lck, [this] { return !queue.empty(); });
            int customer = queue.front();
            queue.pop();
            lck.unlock();

            std::cout << "Торговец " << id << " обслуживает клиента " << customer << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1)); // Имитировать время обслуживания
        }
    }
};

int main() {
    std::vector<std::jthread> traders;
    Trader trader1, trader2, trader3;

    traders.emplace_back(&Trader::startService, &trader1, 1);
    traders.emplace_back(&Trader::startService, &trader2, 2);
    traders.emplace_back(&Trader::startService, &trader3, 3);

    for (int i = 1; i <= 10; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Имитировать время прибытия клиента
        int traderId = (i % 3) + 1; // Распределяйте клиентов между трейдерами по циклической схеме
        switch (traderId) {
            case 1:
                trader1.addToQueue(i);
                break;
            case 2:
                trader2.addToQueue(i);
                break;
            case 3:
                trader3.addToQueue(i);
                break;
            default:
                break;
        }
    }

    for (auto& t : traders) {
        t.join();
    }

    return 0;
}
