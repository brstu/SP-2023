#include <iostream>
#include <thread>
#include <mutex>
#include <string>

std::string sharedString;
std::mutex stringMutex;

void InputThread(int threadNumber) {
    std::string input;
    std::string prompt = (threadNumber == 1) ? "Enter the first string: " : "Enter the second string: ";
    std::cout << prompt;
    std::getline(std::cin, input);

    std::scoped_lock<std::mutex> lock(stringMutex);
    sharedString += input;
}

int main() {

    std::jthread thread1(InputThread, 1);

    std::jthread thread2(InputThread, 2);

    std::cout << "Combined string: " << sharedString << std::endl;

    return 0;
}