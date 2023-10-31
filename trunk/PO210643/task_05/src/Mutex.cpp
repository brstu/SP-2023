#include <iostream>
#include <mutex>
#include <thread>
static std::mutex mutex;


void increment( float value, float &number) {
    std::scoped_lock<std::mutex> lock(mutex);
    number += value;
}
void decrement(float value, float& number) {
    std::scoped_lock<std::mutex> lock(mutex);
    number -= value;
}
void multiply(float value, float& number) {
    std::scoped_lock<std::mutex> lock(mutex);
    number += value;
}



int main() {
    float number = 1.0;


    auto t1 = std::jthread([&number]() { increment(2.3, number); });
    auto t2 = std::jthread([&number]() { decrement(1.2, number); });
    auto t3 = std::jthread([&number]() { multiply(3.6, number); });



    t1.join();
    t2.join();
    t3.join();

    std::cout << "Result value: " << number << std::endl;

    return 0;
}