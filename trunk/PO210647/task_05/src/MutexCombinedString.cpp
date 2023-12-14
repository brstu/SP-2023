#include <iostream>
#include <thread>
#include <mutex>
#include <string>

void InputThread(std::string& sharedString, std::mutex& stringMutex, const std::string& prompt) {//1
    std::string input;//1
    std::cout << prompt;//1
    std::getline(std::cin, input);//1

    std::scoped_lock<std::mutex> lock(stringMutex);//1
    sharedString += input;//1
}

int main() {//1
    std::string sharedString;//1
    std::mutex stringMutex;//1

    std::jthread thread1(InputThread, std::ref(sharedString), std::ref(stringMutex), "Enter the first string: ");//1
    thread1.join();//1

    std::jthread thread2(InputThread, std::ref(sharedString), std::ref(stringMutex), "Enter the second string: ");//1
    thread2.join();//1

    std::cout << "Combined string: " << sharedString << std::endl;//1

    return 0;
}