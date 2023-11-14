#include <iostream>
#include <thread>

using namespace std;

void add(atomic<float>& result) {
	result.store(result.load() + static_cast <float>(1.23123), std::memory_order_relaxed);
}

void sub(atomic<float>& result) {
	result.store(result.load() - static_cast <float>(2.51234), std::memory_order_relaxed);
}

void mul(atomic<float>& result) {
	result.store(result.load() * static_cast <float>(2.01235), std::memory_order_relaxed);
}

int main()
{
	atomic result{ static_cast <float>(5.67293) };

	std::jthread t1(add, std::ref(result));
	std::jthread t2(sub, std::ref(result));
	std::jthread t3(mul, std::ref(result));

	t1.join();
	t2.join();
	t3.join();
	cout << "result: " << result << endl;
	return 0;
}
