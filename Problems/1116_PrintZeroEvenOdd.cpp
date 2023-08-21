//#include <iostream>
//#include <functional>
//#include <thread>
//#include <Mutex>
//#include <condition_variable>
//
//// Question
///*
//	1116. Print Zero Even Odd - August 21st, 2023
//	You have a function printNumber that can be called with an integer parameter and prints it to the console.
//
//	For example, calling printNumber(7) prints 7 to the console.
//	You are given an instance of the class ZeroEvenOdd that has three functions: zero, even, and odd. The same instance of ZeroEvenOdd will be passed to three different threads:
//	
//	Thread A: calls zero() that should only output 0's.
//	Thread B: calls even() that should only output even numbers.
//	Thread C: calls odd() that should only output odd numbers.
//	Modify the given class to output the series "010203040506..." where the length of the series must be 2n.
//	
//	Implement the ZeroEvenOdd class:
//	
//	ZeroEvenOdd(int n) Initializes the object with the number n that represents the numbers that should be printed.
//	void zero(printNumber) Calls printNumber to output one zero.
//	void even(printNumber) Calls printNumber to output one even number.
//	void odd(printNumber) Calls printNumber to output one odd number.
//*/
//
//// Examples
///*
//	Example 1:
//	Input: n = 2
//	Output: "0102"
//	Explanation: There are three threads being fired asynchronously.
//	One of them calls zero(), the other calls even(), and the last one calls odd().
//	"0102" is the correct output.
//	
//	Example 2:
//	Input: n = 5
//	Output: "0102030405"
//*/
//
//// Constraints
///*
//	1 <= n <= 1000
//*/
//
//namespace Question_1116
//{
//	void PrintNumber(int num)
//	{
//		std::cout << num;
//	}
//
//	class ZeroEvenOdd {
//	private:
//		int n;
//		bool mIsZero = true;
//		bool mIsEven = false;
//
//		std::mutex mMutex;
//		std::condition_variable mCV;
//
//	public:
//		ZeroEvenOdd(int n) {
//			this->n = n;
//		}
//
//		// printNumber(x) outputs "x", where x is an integer.
//		void zero(std::function<void(int)> printNumber) 
//		{
//			for (int i = 0; i < n; ++i) 
//			{
//				std::unique_lock<std::mutex> lck(mMutex);
//				mCV.wait(lck, [this]() {return mIsZero == true; });
//
//				mIsZero = false;
//				printNumber(0);
//
//				mCV.notify_all();
//			}
//		}
//
//		void even(std::function<void(int)> printNumber) 
//		{
//			for (int i = 2; i <= n; i += 2) 
//			{
//				std::unique_lock<std::mutex> lck(mMutex);
//				mCV.wait(lck, [this]() {return mIsZero == false && mIsEven == true; });
//
//				mIsZero = true;
//				mIsEven = false;
//				printNumber(i);
//
//				mCV.notify_all();
//			}
//		}
//
//		void odd(std::function<void(int)> printNumber) 
//		{
//			for (int i = 1; i <= n; i += 2) 
//			{
//				std::unique_lock<std::mutex> lck(mMutex);
//				mCV.wait(lck, [this]() {return mIsZero == false && mIsEven == false; });
//
//				mIsZero = true;
//				mIsEven = true;
//				printNumber(i);
//
//				mCV.notify_all();
//			}
//		}
//	};
//
//	void ThreadManager(int index, ZeroEvenOdd& zeroEvenOdd)
//	{
//		switch (index)
//		{
//		case 0:
//			zeroEvenOdd.zero(PrintNumber);
//			break;
//		case 1:
//			zeroEvenOdd.even(PrintNumber);
//			break;
//		case 2:
//			zeroEvenOdd.odd(PrintNumber);
//			break;
//		}
//	}
//}
//
//using namespace Question_1116;
//// Test the code using the examples
//int main()
//{
//	ZeroEvenOdd zeroEvenOdd(5);
//	std::thread t0(ThreadManager, 0, std::ref(zeroEvenOdd));
//	std::thread t1(ThreadManager, 1, std::ref(zeroEvenOdd));
//	std::thread t2(ThreadManager, 2, std::ref(zeroEvenOdd));
//
//	t0.join();
//	t1.join();
//	t2.join();
//
//	// n = 2
//	// 0102
//
//	// n = 5
//	// 0102030405
//}