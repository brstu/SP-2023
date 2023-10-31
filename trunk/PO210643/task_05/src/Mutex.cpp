#include <iostream>
#include <mutex>
#include <thread>

std::mutex mutex;
float number = 0.0;

void increment(float value) {
    std::scoped_lock<std::mutex> lock(mutex);
    number += value;
}

void decrement(float value) {
    std::scoped_lock<std::mutex> lock(mutex);
    number -= value;
}

void multiply(float value) {
    std::scoped_lock<std::mutex> lock(mutex);
    number *= value;
}

int main() {
    std::jthread t1(increment, 2.3);
    std::jthread t2(decrement, 1.5);
    std::jthread t3(multiply, 3.0);

    t1.join();
    t2.join();
    t3.join();

    std::cout << "Result value: " << number << std::endl;

    return 0;
}