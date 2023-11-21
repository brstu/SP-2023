#include <iostream>
#include <mutex>
#include <thread>


void increment( float value, float &number, std::mutex& mutex ) {
    std::scoped_lock<std::mutex> lock(mutex);
    number += value;
}
void decrement(float value, float& number, std::mutex& mutex ) {
    std::scoped_lock<std::mutex> lock(mutex);
    number -= value;
}
void multiply(float value, float& number, std::mutex& mutex ) {
    std::scoped_lock<std::mutex> lock(mutex);
    number *= value;
}



int main() {
    float number = 1.0;
    std::mutex mutex;
    std::jthread thread1(increment, 2.3, std::ref(number), std::ref(mutex));
    thread1.join();

    std::jthread thread2(decrement, 1.2, std::ref(number), std::ref(mutex));
    thread2.join();

    std::jthread thread3(multiply, 3.6, std::ref(number), std::ref(mutex));
    thread3.join();

    std::cout << "Result value: " << number << std::endl;

    return 0;
}