#include <iostream>
#include <thread>

void addition(float &result, float a, float b) {
    result = a + b;
}

void subtraction(float &result, float a, float b) {
    result = a - b;
}

void multiplication(float &result, float a, float b) {
    result = a * b;
}

int main() {
    float a = 5.5, b = 2.2;
    float result_addition, result_subtraction, result_multiplication;

    std::thread t1(addition, std::ref(result_addition), a, b);
    std::thread t2(subtraction, std::ref(result_subtraction), a, b);
    std::thread t3(multiplication, std::ref(result_multiplication), a, b);

    t1.join();
    t2.join();
    t3.join();

    std::cout << "Result of addition: " << result_addition << std::endl;
    std::cout << "Result of subtraction: " << result_subtraction << std::endl;
    std::cout << "Result of multiplication: " << result_multiplication << std::endl;

    return 0;
}
