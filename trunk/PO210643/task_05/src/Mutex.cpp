#include <iostream>
#include <mutex>
#include <thread>

std::mutex mutex;
float number = 0.0;

void increment(float value) {
    std::lock_guard<std::mutex> lock(mutex);
    number += value;
}

void decrement(float value) {
    std::lock_guard<std::mutex> lock(mutex);
    number -= value;
}

void multiply(float value) {
    std::lock_guard<std::mutex> lock(mutex);
    number *= value;
}

int main() {
    std::thread t1(increment, 2.3);
    std::thread t2(decrement, 1.5);
    std::thread t3(multiply, 3.0);

    t1.join();
    t2.join();
    t3.join();

    std::cout << "Result value: " << number << std::endl;

    return 0;
}