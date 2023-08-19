//#include <iostream>
//#include <functional>
//#include <mutex>
//
//// Question
///*
//	1114. Print in Order - August 25th, 2023
//	Suppose we have a class:
//
//	public class Foo {
//	  public void first() { print("first"); }
//	  public void second() { print("second"); }
//	  public void third() { print("third"); }
//	}
//	The same instance of Foo will be passed to three different threads. Thread A will call first(), thread B will call second(), and thread C will call third(). Design a mechanism and modify the program to ensure that second() is executed after first(), and third() is executed after second().
//	
//	Note:
//	We do not know how the threads will be scheduled in the operating system, even though the numbers in the input seem to imply the ordering. The input format you see is mainly to ensure our tests' comprehensiveness.
//*/
//
//// Examples
///*
//	Example 1:
//	Input: nums = [1,2,3]
//	Output: "firstsecondthird"
//	Explanation: There are three threads being fired asynchronously. The input [1,2,3] means thread A calls first(), thread B calls second(), and thread C calls third(). "firstsecondthird" is the correct output.
//	
//	Example 2:
//	Input: nums = [1,3,2]
//	Output: "firstsecondthird"
//	Explanation: The input [1,3,2] means thread A calls first(), thread B calls third(), and thread C calls second(). "firstsecondthird" is the correct output.
//*/
//
//// Constraints
///*
//	nums is a permutation of [1, 2, 3].
//*/
//
//namespace Question_1114
//{
//	void printFirst()
//	{
//		std::cout << "first";
//	}
//
//	void printSecond()
//	{
//		std::cout << "second";
//	}
//
//	void printThird()
//	{
//		std::cout << "third";
//	}
//
//	class Foo 
//	{
//	public:
//		Foo() 
//		{
//
//		}
//
//		void first(std::function<void()> printFirst) 
//		{
//			// printFirst() outputs "first". Do not change or remove this line.
//			printFirst();
//			firstIsCalled = true;
//			mFirstCV.notify_one();
//		}
//
//		void second(std::function<void()> printSecond) 
//		{
//			// printSecond() outputs "second". Do not change or remove this line.
//			std::unique_lock<std::mutex> ul(mMutex);
//			mFirstCV.wait(ul, [this] {return firstIsCalled == true; });
//
//			printSecond();
//
//			ul.unlock();
//			secondIsCalled = true;
//			mSecondCV.notify_one();
//		}
//
//		void third(std::function<void()> printThird) 
//		{
//			// printThird() outputs "third". Do not change or remove this line.
//			std::unique_lock<std::mutex> ul(mMutex);
//			mSecondCV.wait(ul, [this] {return secondIsCalled == true; });
//
//			printThird();
//
//			ul.unlock();
//		}
//
//	private:
//		bool firstIsCalled = false;
//		bool secondIsCalled = false;
//
//		std::mutex mMutex;
//		std::condition_variable mFirstCV;
//		std::condition_variable mSecondCV;
//	};
//
//	void TempCall(int num, Foo& foo)
//	{
//		if (num == 1)
//		{
//			foo.first(printFirst);
//		}
//		else if (num == 2)
//		{
//			foo.second(printSecond);
//		}
//		else
//		{
//			foo.third(printThird);
//		}
//	}
//}
//
//using namespace Question_1114;
//// Test the code using the examples
//int main()
//{
//	Foo foo;
//	std::thread t1(TempCall, 1, std::ref(foo));
//	std::thread t2(TempCall, 2, std::ref(foo));
//	std::thread t3(TempCall, 3, std::ref(foo));
//
//	t1.join();
//	t2.join();
//	t3.join();
//}