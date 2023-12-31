﻿#include <iostream>
#include <thread>
#include <mutex>

int main() {
    int initialValue;
    std::cout << "Enter the initial value: ";
    std::cin >> initialValue;

    int counter = initialValue;
    std::mutex counterMutex;

    int numIncrements;
    std::cout << "Enter the number of increments: ";
    std::cin >> numIncrements;

    int numDecrements;
    std::cout << "Enter the number of decrements: ";
    std::cin >> numDecrements;

    int numDecrementsDoubled = numDecrements * 2;

    std::jthread incrementThread([&counter, numIncrements, &counterMutex]() {
        for (int i = 0; i < numIncrements; ++i) {
            std::lock_guard lock(counterMutex);
            counter++;
        }
        });

    std::jthread decrementThread([&counter, numDecrementsDoubled, &counterMutex]() {
        for (int i = 0; i < numDecrementsDoubled; ++i) {
            std::lock_guard lock(counterMutex);
            counter--;
        }
        });

    incrementThread.join();
    decrementThread.join();

    std::cout << "Doubled decrements: " << numDecrementsDoubled << std::endl;
    std::cout << "Final value with doubled decrements: " << counter << std::endl;

    return 0;
}
