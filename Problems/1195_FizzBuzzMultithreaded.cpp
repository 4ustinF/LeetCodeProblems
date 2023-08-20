//#include <iostream>
//#include <functional>
//#include <mutex>
//#include <thread>
//
//// Question
///*
//	1195. Fizz Buzz Multithreaded - August 19th, 2023
//	You have the four functions:
//
//	printFizz that prints the word "fizz" to the console,
//	printBuzz that prints the word "buzz" to the console,
//	printFizzBuzz that prints the word "fizzbuzz" to the console, and
//	printNumber that prints a given integer to the console.
//	You are given an instance of the class FizzBuzz that has four functions: fizz, buzz, fizzbuzz and number. The same instance of FizzBuzz will be passed to four different threads:
//
//	Thread A: calls fizz() that should output the word "fizz".
//	Thread B: calls buzz() that should output the word "buzz".
//	Thread C: calls fizzbuzz() that should output the word "fizzbuzz".
//	Thread D: calls number() that should only output the integers.
//	Modify the given class to output the series [1, 2, "fizz", 4, "buzz", ...] where the ith token (1-indexed) of the series is:
//
//	"fizzbuzz" if i is divisible by 3 and 5,
//	"fizz" if i is divisible by 3 and not 5,
//	"buzz" if i is divisible by 5 and not 3, or
//	i if i is not divisible by 3 or 5.
//	Implement the FizzBuzz class:
//
//	FizzBuzz(int n) Initializes the object with the number n that represents the length of the sequence that should be printed.
//	void fizz(printFizz) Calls printFizz to output "fizz".
//	void buzz(printBuzz) Calls printBuzz to output "buzz".
//	void fizzbuzz(printFizzBuzz) Calls printFizzBuzz to output "fizzbuzz".
//	void number(printNumber) Calls printnumber to output the numbers.
//*/
//
//// Examples
///*
//	Example 1:
//	Input: n = 15
//	Output: [1,2,"fizz",4,"buzz","fizz",7,8,"fizz","buzz",11,"fizz",13,14,"fizzbuzz"]
//
//	Example 2:
//	Input: n = 5
//	Output: [1,2,"fizz",4,"buzz"]
//*/
//
//// Constraints
///*
//	1 <= n <= 50
//*/
//
//namespace Question_1195
//{
//	void printFizz()
//	{
//		std::cout << "fizz ";
//	}
//
//	void printBuzz()
//	{
//		std::cout << "buzz ";
//	}
//
//	void printFizzBuzz()
//	{
//		std::cout << "fizzbuzz ";
//	}
//
//	void printNumber(int x)
//	{
//		std::cout << x << " ";
//	}
//
//	class FizzBuzz {
//	private:
//		int n;
//		int mCount = 1;
//
//		std::mutex mMutex;
//		std::condition_variable mCV;
//
//		void IncrementAndNotify()
//		{
//			++mCount;
//			mCV.notify_all();
//		}
//
//	public:
//		FizzBuzz(int n) {
//			this->n = n;
//		}
//
//		// printFizz() outputs "fizz".
//		void fizz(std::function<void()> printFizz)
//		{
//			while (true)
//			{
//				std::unique_lock<std::mutex> ul(mMutex);
//				mCV.wait(ul, [this] {return (mCount % 15 != 0 && mCount % 3 == 0) || mCount > n; });
//				ul.unlock();
//
//				if (mCount > n)
//				{
//					return;
//				}
//
//				printFizz();
//				IncrementAndNotify();
//			}
//		}
//
//		// printBuzz() outputs "buzz".
//		void buzz(std::function<void()> printBuzz)
//		{
//			while (true)
//			{
//				std::unique_lock<std::mutex> ul(mMutex);
//				mCV.wait(ul, [this] {return (mCount % 15 != 0 && mCount % 5 == 0) || mCount > n; });
//				ul.unlock();
//
//				if (mCount > n)
//				{
//					return;
//				}
//
//				printBuzz();
//				IncrementAndNotify();
//			}
//		}
//
//		// printFizzBuzz() outputs "fizzbuzz".
//		void fizzbuzz(std::function<void()> printFizzBuzz)
//		{
//			while (true)
//			{
//				std::unique_lock<std::mutex> ul(mMutex);
//				mCV.wait(ul, [this] {return mCount % 15 == 0 || mCount > n; });
//				ul.unlock();
//
//				if (mCount > n)
//				{
//					return;
//				}
//
//				printFizzBuzz();
//				IncrementAndNotify();
//			}
//		}
//
//		// printNumber(x) outputs "x", where x is an integer.
//		void number(std::function<void(int)> printNumber)
//		{
//			while (true)
//			{
//				std::unique_lock<std::mutex> ul(mMutex);
//				mCV.wait(ul, [this] {return (mCount % 15 != 0 && mCount % 5 != 0 && mCount % 3 != 0) || mCount > n; });
//				ul.unlock();
//
//				if (mCount > n)
//				{
//					return;
//				}
//
//				printNumber(mCount);
//				IncrementAndNotify();
//			}
//		}
//
//	};
//
//	void ThreadController(int command, FizzBuzz& fizzBuzz)
//	{
//		switch (command)
//		{
//		case 0:
//			fizzBuzz.fizz(printFizz);
//			break;
//		case 1:
//			fizzBuzz.buzz(printBuzz);
//			break;
//		case 2:
//			fizzBuzz.fizzbuzz(printFizzBuzz);
//			break;
//		case 3:
//			fizzBuzz.number(printNumber);
//			break;
//		}
//	}
//}
//
//using namespace Question_1195;
//// Test the code using the examples
//int main()
//{
//	// Example 1 = [1, 2, "fizz", 4, "buzz", "fizz", 7, 8, "fizz", "buzz", 11, "fizz", 13, 14, "fizzbuzz"]
//	FizzBuzz fizzbuzz(15);
//
//	// Example 2 = [1, 2, "fizz", 4, "buzz"]
//	//FizzBuzz fizzbuzz(5);
//
//	std::thread t0(ThreadController, 0, std::ref(fizzbuzz));
//	std::thread t1(ThreadController, 1, std::ref(fizzbuzz));
//	std::thread t2(ThreadController, 2, std::ref(fizzbuzz));
//	std::thread t3(ThreadController, 3, std::ref(fizzbuzz));
//
//	t0.join();
//	t1.join();
//	t2.join();
//	t3.join();
//}