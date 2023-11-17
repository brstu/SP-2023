#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

void add(float& result, std::mutex& resultMutex) {
	std::scoped_lock<std::mutex> lock(resultMutex);
	result += static_cast <float>(1.23123);
}

void sub(float& result, std::mutex& resultMutex) {
	std::scoped_lock<std::mutex> lock(resultMutex);
	result -= static_cast <float>(2.51234);
}

void mul(float& result, std::mutex& resultMutex) {
	std::scoped_lock<std::mutex> lock(resultMutex);
	result *= static_cast <float>(2.01235);
}

int main()
{
	std::mutex resultMutex;
	auto result = static_cast <float>(5.67293);

	std::jthread t1 (add, std::ref(result), std::ref(resultMutex));
	std::jthread t2 (sub, std::ref(result), std::ref(resultMutex));
	std::jthread t3 (mul, std::ref(result), std::ref(resultMutex));

	t1.join();
	t2.join();
	t3.join();
	cout << "result: " << result << endl;
	return 0;
}
