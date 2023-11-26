#include <iostream>
#include <vector>
#include <algorithm>
#include <mutex>
#include <random>
#include <queue>
#include <Windows.h>

void firstSeller(std::queue<int> &firstSellerQueue, std::queue<int> &secondSellerQueue, std::queue<int> &thirdSellerQueue, std::mutex& firstSellerMutex, std::mutex& secondSellerMutex, std::mutex& thirdSellerMutex) {
	while (true) {
		int temp;
		if (!firstSellerQueue.empty()) {
			std::scoped_lock<std::mutex> lock(firstSellerMutex);
			std::cout << "1 seller service customer from 1 seller queue" << std::endl;
			temp = firstSellerQueue.front();
			firstSellerQueue.pop();
		}
		else {
			break;
		}
		Sleep(temp*1000);
		std::cout << "1 seller finished service customer from 1 seller queue" << std::endl;
	}

	while (true) {
		int temp;
		if (!secondSellerQueue.empty()) {
			std::scoped_lock<std::mutex> lock(secondSellerMutex);
			std::cout << "1 seller service customer from 2 seller queue" << std::endl;
			temp = secondSellerQueue.front();
			secondSellerQueue.pop();
		}
		else {
			break;
		}
		Sleep(temp * 1000);
		std::cout << "1 seller finished service customer from 2 seller queue" << std::endl;
	}

	while (true) {
		int temp;
		if (!thirdSellerQueue.empty()) {
			std::scoped_lock<std::mutex> lock(thirdSellerMutex);
			std::cout << "1 seller service customer from 3 seller queue" << std::endl;
			temp = thirdSellerQueue.front();
			thirdSellerQueue.pop();
			
		}
		else {
			break;
		}
		Sleep(temp * 1000);
		std::cout << "1 seller finished service customer from 3 seller queue" << std::endl;
	}
}

void secondSeller(std::queue<int>& firstSellerQueue, std::queue<int>& secondSellerQueue, std::queue<int>& thirdSellerQueue, std::mutex& firstSellerMutex, std::mutex& secondSellerMutex, std::mutex& thirdSellerMutex) {
	Sleep(5);
	while (true) {
		int temp;
		if (!secondSellerQueue.empty()) {
			std::scoped_lock<std::mutex> lock(secondSellerMutex);
			std::cout << "2 seller service customer from 2 seller queue" << std::endl;
			temp = secondSellerQueue.front();
			secondSellerQueue.pop();
		}
		else {
			break;
		}
		Sleep(temp * 1000);
		std::cout << "2 seller finished service customer from 2 seller queue" << std::endl;
	}

	while (true) {
		int temp;
		if (!thirdSellerQueue.empty()) {
			std::scoped_lock<std::mutex> lock(thirdSellerMutex);
			std::cout << "2 seller service customer from 3 seller queue" << std::endl;
			temp = thirdSellerQueue.front();
			thirdSellerQueue.pop();
		}
		else {
			break;
		}
		Sleep(temp * 1000);
		std::cout << "2 seller finished service customer from 3 seller queue" << std::endl;
	}

	while (true) {
		int temp;
		if (!firstSellerQueue.empty()) {
			std::scoped_lock<std::mutex> lock(firstSellerMutex);
			std::cout << "2 seller service customer from 1 seller queue" << std::endl;
			temp = firstSellerQueue.front();
			firstSellerQueue.pop();
			
		}
		else {
			break;
		}
		Sleep(temp * 1000);
		std::cout << "2 seller finished service customer from 1 seller queue" << std::endl;
	}
}

void thirdSeller(std::queue<int>& firstSellerQueue, std::queue<int>& secondSellerQueue, std::queue<int>& thirdSellerQueue, std::mutex& firstSellerMutex, std::mutex& secondSellerMutex, std::mutex& thirdSellerMutex) {
	Sleep(15);
	while (true) {
		int temp;
		if (!thirdSellerQueue.empty()) {
			std::scoped_lock<std::mutex> lock(thirdSellerMutex);
			std::cout << "3 seller service customer from 3 seller queue" << std::endl;
			temp = thirdSellerQueue.front();
			thirdSellerQueue.pop();
			
		}
		else {
			break;
		}
		Sleep(temp * 1000);
		std::cout << "3 seller finished service customer from 3 seller queue" << std::endl;
	}

	while (true) {
		int temp;
		if (!firstSellerQueue.empty()) {
			std::scoped_lock<std::mutex> lock(firstSellerMutex);
			std::cout << "3 seller service customer from 1 seller queue" << std::endl;
			temp = firstSellerQueue.front();
			firstSellerQueue.pop();
			
		}
		else {
			break;
		}
		Sleep(temp * 1000);
		std::cout << "3 seller finished service customer from 1 seller queue" << std::endl;
	}

	while (true) {
		int temp;
		if (!secondSellerQueue.empty()) {
			std::scoped_lock<std::mutex> lock(secondSellerMutex);
			std::cout << "3 seller service customer from 2 seller queue" << std::endl;
			temp = secondSellerQueue.front();
			secondSellerQueue.pop();
			
		}
		else {
			break;
		}
		Sleep(temp * 1000);
		std::cout << "3 seller finished service customer from 2 seller queue" << std::endl;
	}
}

int main()
{
	system("color f0");

	std::random_device rd{};
	const int minThreshold = 1;
	const int maxThreshold = 10;
	std::uniform_int_distribution<> distrib(minThreshold, maxThreshold);
	int firstSellerQueueSize = distrib(rd);
	int secondSellerQueueSize = distrib(rd);
	int thirdSellerQueueSize = distrib(rd);

	std::queue<int> firstSellerQueue;
	std::queue<int> secondSellerQueue;
	std::queue<int> thirdSellerQueue;

	for (int i = 0; i < firstSellerQueueSize; i++) {
		firstSellerQueue.push(distrib(rd));
	}
	for (int i = 0; i < secondSellerQueueSize; i++) {
		secondSellerQueue.push(distrib(rd));
	}
	for (int i = 0; i < thirdSellerQueueSize; i++) {
		thirdSellerQueue.push(distrib(rd));
	}
	
	std::mutex firstSellerMutex;
	std::mutex secondSellerMutex;
	std::mutex thirdSellerMutex;

	std::cout << "first seller queue size: " << firstSellerQueueSize << std::endl;
	std::cout << "second seller queue size: " << secondSellerQueueSize << std::endl;
	std::cout << "third seller queue size: " << thirdSellerQueueSize << std::endl;

	std::jthread t1(firstSeller, std::ref(firstSellerQueue), std::ref(secondSellerQueue), std::ref(thirdSellerQueue), std::ref(firstSellerMutex), std::ref(secondSellerMutex), std::ref(thirdSellerMutex));
	std::jthread t2(secondSeller, std::ref(firstSellerQueue), std::ref(secondSellerQueue), std::ref(thirdSellerQueue), std::ref(firstSellerMutex), std::ref(secondSellerMutex), std::ref(thirdSellerMutex));
	std::jthread t3(thirdSeller, std::ref(firstSellerQueue), std::ref(secondSellerQueue), std::ref(thirdSellerQueue), std::ref(firstSellerMutex), std::ref(secondSellerMutex), std::ref(thirdSellerMutex));


	t1.join();
	t2.join();
	t3.join();
}
