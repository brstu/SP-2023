#include <iostream>
#include <thread>
#include <mutex>
#include <string>

void InputThread(std::string& sharedString, std::mutex& stringMutex, const std::string& prompt) {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);

    std::scoped_lock<std::mutex> lock(stringMutex);
    sharedString += input;
}

int main() {
    std::string sharedString;
    std::mutex stringMutex;

    std::jthread thread1(InputThread, std::ref(sharedString), std::ref(stringMutex), "Enter the first string: ");
    thread1.join();

    std::jthread thread2(InputThread, std::ref(sharedString), std::ref(stringMutex), "Enter the second string: ");
    thread2.join();

    std::cout << "Combined string: " << sharedString << std::endl;

    return 0;
}