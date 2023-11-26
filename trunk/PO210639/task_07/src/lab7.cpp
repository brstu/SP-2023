#include <iostream>
#include <vector>
#include <algorithm>
#include <mutex>
#include <random>
#include <queue>
#include <Windows.h>

void serviceCustomer(std::queue<int>& sellerQueue, std::mutex& sellerMutex, std::string sellerIndex, std::string queueIndex) {
	while (true) {
		int temp;
		if (!sellerQueue.empty()) {
			std::scoped_lock<std::mutex> lock(sellerMutex);
			std::cout << sellerIndex + " seller service customer from " + queueIndex + " seller queue" << std::endl;
			temp = sellerQueue.front();
			sellerQueue.pop();
		}
		else {
			break;
		}
		Sleep(temp * 1000);
		std::cout << sellerIndex + " seller finished service customer from " + queueIndex + " seller queue" << std::endl;
	}
}

void firstSeller(std::queue<int> &firstSellerQueue, std::queue<int> &secondSellerQueue, std::queue<int> &thirdSellerQueue, std::mutex& firstSellerMutex, std::mutex& secondSellerMutex, std::mutex& thirdSellerMutex) {

	serviceCustomer(firstSellerQueue, firstSellerMutex, "1", "1");

	serviceCustomer(secondSellerQueue, secondSellerMutex, "1", "2");

	serviceCustomer(thirdSellerQueue, thirdSellerMutex, "1", "3");
}

void secondSeller(std::queue<int>& firstSellerQueue, std::queue<int>& secondSellerQueue, std::queue<int>& thirdSellerQueue, std::mutex& firstSellerMutex, std::mutex& secondSellerMutex, std::mutex& thirdSellerMutex) {
	
	Sleep(5);

	serviceCustomer(secondSellerQueue, secondSellerMutex, "2", "2");

	serviceCustomer(thirdSellerQueue, thirdSellerMutex, "2", "3");
	
	serviceCustomer(firstSellerQueue, firstSellerMutex, "2", "1");
}

void thirdSeller(std::queue<int>& firstSellerQueue, std::queue<int>& secondSellerQueue, std::queue<int>& thirdSellerQueue, std::mutex& firstSellerMutex, std::mutex& secondSellerMutex, std::mutex& thirdSellerMutex) {
	
	Sleep(15);

	serviceCustomer(thirdSellerQueue, thirdSellerMutex, "3", "3");
	
	serviceCustomer(firstSellerQueue, firstSellerMutex, "3", "1");

	serviceCustomer(secondSellerQueue, secondSellerMutex, "3", "2");
}

int main()
{
	system("color f0");

	std::random_device rd{};
	const int minThreshold = 1;
	const int maxThreshold = 10;
	std::uniform_int_distribution distrib(minThreshold, maxThreshold);
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
