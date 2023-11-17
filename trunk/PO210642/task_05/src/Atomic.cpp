﻿#include <iostream>
#include <atomic>
#include <thread>

int main() {
    std::atomic<int> counter{ 0 };

    int numIncrements;
    int numDecrements;
    int initialValue;

    std::cout << "Enter the initial value: ";
    std::cin >> initialValue;

    std::cout << "Enter the number of increments: ";
    std::cin >> numIncrements;

    std::cout << "Enter the number of decrements: ";
    std::cin >> numDecrements;

    counter.store(initialValue);

    std::thread incrementThread([&counter, numIncrements]() {
        for (int i = 0; i < numIncrements; ++i) {
            counter.fetch_add(1);
        }
        });

    std::thread decrementThread([&counter, numDecrements]() {
        for (int i = 0; i < numDecrements; ++i) {
            counter.fetch_sub(1);
        }
        });

    incrementThread.join();
    decrementThread.join();

    std::cout << "Final value: " << counter.load() << std::endl;

    return 0;
}