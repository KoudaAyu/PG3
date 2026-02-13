#include<stdio.h>
#include<thread>
#include<mutex>
#include<condition_variable>

void Double(int num)
{
	num *= 2;
	printf("num * 2: %d\n", num);
}

void AddTwo(int num)
{
	num += 2;
	printf("num + 2: %d\n", num);
}

void Increment(int num)
{
	num += 1;
	printf("num + 1: %d\n", num);
}

int main()
{
	int num = 3;

	std::mutex mtx;
	std::condition_variable cv;
	int turn = 1; // 1 -> Double, 2 -> AddTwo, 3 -> Increment

	std::thread th1([&]() {
		std::unique_lock<std::mutex> lk(mtx);
		cv.wait(lk, [&]() { return turn == 1; });
		Double(num);
		turn = 2;
		lk.unlock();
		cv.notify_all();
	});

	std::thread th2([&]() {
		std::unique_lock<std::mutex> lk(mtx);
		cv.wait(lk, [&]() { return turn == 2; });
		AddTwo(num);
		turn = 3;
		lk.unlock();
		cv.notify_all();
	});

	std::thread th3([&]() {
		std::unique_lock<std::mutex> lk(mtx);
		cv.wait(lk, [&]() { return turn == 3; });
		Increment(num);
		turn = 4;
		lk.unlock();
		cv.notify_all();
	});

	th1.join();
	th2.join();
	th3.join();

	return 0;
}