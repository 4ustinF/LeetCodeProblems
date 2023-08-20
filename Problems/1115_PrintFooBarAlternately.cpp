//#include <iostream>
//#include <functional>
//#include <thread>
//#include <mutex>
//
//// Question
///*
//	1115. Print FooBar Alternately - August 20th, 2023
//    Suppose you are given the following code:
//
//    class FooBar {
//      public void foo() {
//        for (int i = 0; i < n; i++) {
//          print("foo");
//        }
//      }
//    
//      public void bar() {
//        for (int i = 0; i < n; i++) {
//          print("bar");
//        }
//      }
//    }
//    The same instance of FooBar will be passed to two different threads:
//    
//    thread A will call foo(), while
//    thread B will call bar().
//    Modify the given program to output "foobar" n times.
//*/
//
//// Examples
///*
//    Example 1:
//    Input: n = 1
//    Output: "foobar"
//    Explanation: There are two threads being fired asynchronously. One of them calls foo(), while the other calls bar().
//    "foobar" is being output 1 time.
//    
//    Example 2:
//    Input: n = 2
//    Output: "foobarfoobar"
//    Explanation: "foobar" is being output 2 times.
//*/
//
//// Constraints
///*
//    1 <= n <= 1000
//*/
//
//namespace Question_1115
//{
//    void printFoo()
//    {
//        std::cout << "foo";
//    }
//
//    void printBar()
//    {
//        std::cout << "bar, ";
//    }
//
//    class FooBar {
//    private:
//        int n;
//        std::mutex mMutex;
//        std::condition_variable mCV;
//
//        bool isFoo = true;
//
//    public:
//        FooBar(int n) {
//            this->n = n;
//        }
//
//        void foo(std::function<void()> printFoo) 
//        {
//            for (int i = 0; i < n; i++) 
//            {
//                std::unique_lock<std::mutex> ul(mMutex);
//                mCV.wait(ul, [this] {return isFoo == true; });
//
//                printFoo();
//                isFoo = false;
//
//                ul.unlock();
//                mCV.notify_one();
//            }
//        }
//
//        void bar(std::function<void()> printBar) 
//        {
//            for (int i = 0; i < n; i++) 
//            {
//                std::unique_lock<std::mutex> ul(mMutex);
//                mCV.wait(ul, [this] {return isFoo == false; });
//
//                printBar();
//                isFoo = true;
//
//                ul.unlock();
//                mCV.notify_one();
//            }
//        }
//    };
//
//    void ThreadController(bool isFoo, FooBar& fooBar)
//    {
//        isFoo ? fooBar.foo(printFoo) : fooBar.bar(printBar);
//    }
//}
//
//using namespace Question_1115;
//// Test the code using the examples
//int main()
//{
//    FooBar foobar(10);
//
//    std::thread t0(ThreadController, true, std::ref(foobar));
//    std::thread t1(ThreadController, false, std::ref(foobar));
//
//    t0.join();
//    t1.join();
//}