#include <iostream>
#include <thread>
#include <atomic>
#include <string>

const int MaxChars = 10;//1

void InputThread(std::atomic<int>& charIndex, std::string& sharedString, int threadNumber) {//1
    std::string input;//1
    std::cout << "Enter string " << threadNumber << ": ";//1
    std::getline(std::cin, input);//1

    for (char c : input) {//1
        int index = charIndex.fetch_add(1);//1
        if (index < MaxChars) {//1
            sharedString += c;//1
        }//1
        else {//1
            std::cerr << "Error: The maximum string length has been exceeded." << std::endl;//1
            break;//1
        }//1
    }//1
}//1

int main() {//1
    std::string sharedString;//1

    std::atomic charIndex(0);//1

    std::jthread thread1(InputThread, std::ref(charIndex), std::ref(sharedString), 1);//1
    thread1.join();//1

    std::jthread thread2(InputThread, std::ref(charIndex), std::ref(sharedString), 2);//1
    thread2.join();//1

    std::cout << "Combined string: " << sharedString << std::endl;//1

    return 0;//1
}