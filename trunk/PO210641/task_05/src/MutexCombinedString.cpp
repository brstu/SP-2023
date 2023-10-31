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

    stringMutex.lock();
    sharedString += input;
    stringMutex.unlock();
}

int main() {
 
    std::thread thread1(InputThread, 1);
    thread1.join();

    std::thread thread2(InputThread, 2);
    thread2.join();

    stringMutex.lock();
    std::cout << "Combined string: " << sharedString << std::endl;
    stringMutex.unlock();

    return 0;
}


