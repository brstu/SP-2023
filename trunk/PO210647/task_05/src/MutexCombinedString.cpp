#include <iostream>
#include <thread>
#include <mutex>
#include <string>

void InputThread(std::string& sharedString, std::mutex& stringMutex, const std::string& prompt) {//1//210647
    std::string input;//1//210647
    std::cout << prompt;//1//210647
    std::getline(std::cin, input);//1//210647

    std::scoped_lock<std::mutex> lock(stringMutex);//1//210647
    sharedString += input;//1//210647
}

int main() {//1//210647
    std::string sharedString;//1//210647
    std::mutex stringMutex;//1//210647

    std::jthread thread1(InputThread, std::ref(sharedString), std::ref(stringMutex), "Enter the first string: ");//1//210647
    thread1.join();//1//210647

    std::jthread thread2(InputThread, std::ref(sharedString), std::ref(stringMutex), "Enter the second string: ");//1//210647
    thread2.join();//1//210647

    std::cout << "Combined string: " << sharedString << std::endl;//1//210647

    return 0;
}