#include <iostream>
#include <string.h>
#include <thread>

std::atomic<float> result_value{ 2.93 };

 std::jthread thread1 = std::jthread([] {
	result_value.store(result_value.load() + 1.26, std::memory_order_relaxed);
	});

std::jthread thread2 = std::jthread([] {
	result_value.store(result_value.load() - 1.83, std::memory_order_relaxed);
	});

std::jthread thread3 = std::jthread([] {
	result_value.store(result_value.load() * 7.03, std::memory_order_relaxed);
	});

int main()
{
	thread1.join();
	thread2.join();
	thread3.join();
	std::cout << "Result value: " << result_value << std::endl;
	return 0;
}