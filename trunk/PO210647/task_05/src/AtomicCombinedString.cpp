#include <iostream>
#include <thread>
#include <atomic>
#include <string>

const int MaxChars = 10;//1//210647

void InputThread(std::atomic<int>& charIndex, std::string& sharedString, int threadNumber) {//1//210647
    std::string input;//1//210647
    std::cout << "Enter string " << threadNumber << ": ";//1//210647
    std::getline(std::cin, input);//1//210647

    for (char c : input) {//1//210647
        int index = charIndex.fetch_add(1);//1//210647
        if (index < MaxChars) {//1//210647
            sharedString += c;//1//210647
        }//1//210647
        else {//1//210647
            std::cerr << "Error: The maximum string length has been exceeded." << std::endl;//1//210647
            break;//1//210647
        }//1//210647
    }//1//210647
}//1//210647

int main() {//1//210647
    std::string sharedString;//1//210647

    std::atomic charIndex(0);//1//210647

    std::jthread thread1(InputThread, std::ref(charIndex), std::ref(sharedString), 1);//1//210647
    thread1.join();//1//210647

    std::jthread thread2(InputThread, std::ref(charIndex), std::ref(sharedString), 2);//1//210647
    thread2.join();//1//210647

    std::cout << "Combined string: " << sharedString << std::endl;//1//210647

    return 0;//1//210647
}