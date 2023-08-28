//#include <iostream>
//#include <queue>
//
//// Question
///*
//	225. Implement Stack using Queues - August 28th, 2023
//	Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).
//
//	Implement the MyStack class:
//	
//	void push(int x) Pushes element x to the top of the stack.
//	int pop() Removes the element on the top of the stack and returns it.
//	int top() Returns the element on the top of the stack.
//	boolean empty() Returns true if the stack is empty, false otherwise.
//	Notes:
//	
//	You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
//	Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.
//*/
//
//// Examples
///*
//	Example 1:
//	
//	Input
//	["MyStack", "push", "push", "top", "pop", "empty"]
//	[[], [1], [2], [], [], []]
//	Output
//	[null, null, null, 2, 2, false]
//	
//	Explanation
//	MyStack myStack = new MyStack();
//	myStack.push(1);
//	myStack.push(2);
//	myStack.top(); // return 2
//	myStack.pop(); // return 2
//	myStack.empty(); // return False
//*/
//
//// Constraints
///*
//	1 <= x <= 9
//	At most 100 calls will be made to push, pop, top, and empty.
//	All the calls to pop and top are valid.
//*/
//
//namespace Question_225
//{
//	class MyStack 
//	{
//	public:
//		MyStack() 
//		{
//
//		}
//
//		void push(int x) 
//		{
//			// Pushes element x to the top of the stack.
//			mQueue.push(x);
//		}
//
//		int pop() 
//		{
//			// Get ref to the value being removed
//			const int value = top();
//
//			// Removes the element on the top of the stack and returns it.
//			std::queue<int> mSwapQueue;
//			while (!mQueue.empty())
//			{
//				int o = mQueue.front();
//				mQueue.pop();
//
//				if (!mQueue.empty())
//				{
//					mSwapQueue.push(o);
//				}
//			}
//			std::swap(mQueue, mSwapQueue);
//
//			return value;
//		}
//
//		int top() 
//		{
//			// Returns the element on the top of the stack.
//			return mQueue.back();
//		}
//
//		bool empty() 
//		{
//			// Returns true if the stack is empty, false otherwise.
//			return mQueue.empty();
//		}
//
//	private:
//		std::queue<int> mQueue; // fifo
//	};
//}
//
//using namespace Question_225;
//// Test the code using the examples
//int main()
//{
//	// Example 1 = [null, null, null, 2, 2, false]
//	MyStack* obj = new MyStack();
//	obj->push(1);
//	obj->push(2);
//	int param_3 = obj->top();
//	int param_2 = obj->pop();
//	bool param_4 = obj->empty();
//
//	std::cout << "End\n";
//}