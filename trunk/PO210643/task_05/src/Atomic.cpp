#include <iostream>
#include <string.h>
#include <thread>

void increment(std::atomic<float>& result_value) {
	result_value.store(result_value.load() + 2.72, std::memory_order_relaxed);
};
void decrement(std::atomic<float>& result_value) {
	result_value.store(result_value.load() - 1.73, std::memory_order_relaxed);
};
void multiply(std::atomic<float>& result_value) {
	result_value.store(result_value.load() * 3.2, std::memory_order_relaxed);
};


int main()
{
	std::atomic<float> result_value{ 1.0 };
	auto thread1 = std::jthread([&result_value]() { increment(result_value); });
	auto thread2 = std::jthread([&result_value]() { decrement(result_value); });
	auto thread3 = std::jthread([&result_value]() { multiply(result_value); });

	thread1.join();
	thread2.join();
	thread3.join();
	std::cout << "Result value: " << result_value << std::endl;
	return 0;
}