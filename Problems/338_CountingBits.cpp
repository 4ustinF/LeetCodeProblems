//#include <iostream>
//#include <vector>
//
//// Question
///*
//	338. Counting Bits - Semptember 1st, 2023
//	Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
//*/
//
//// Examples
///*
//	Example 1:
//	Input: n = 2
//	Output: [0,1,1]
//	Explanation:
//	0 --> 0
//	1 --> 1
//	2 --> 10
//
//	Example 2:
//	Input: n = 5
//	Output: [0,1,1,2,1,2]
//	Explanation:
//	0 --> 0
//	1 --> 1
//	2 --> 10
//	3 --> 11
//	4 --> 100
//	5 --> 101
//*/
//
//// Constraints
///*
//	0 <= n <= 10^5
//*/
//
//// Follow Up
///*
//	It is very easy to come up with a solution with a runtime of O(n log n). Can you do it in linear time O(n) and possibly in a single pass?
//	Can you do it without using any built-in function (i.e., like __builtin_popcount in C++)?
//*/
//
//namespace Question_338
//{
//	std::vector<int> CountBits(int n)
//	{
//		std::vector<int> ans;
//		ans.reserve(n + 1);
//		ans.push_back(0);
//
//		// We can compute current set bit count using previous count as i / 2
//		// i % 2 will be 0 for even number and 1 for odd number
//		for (int i = 1; i <= n; ++i)
//		{
//			ans.push_back(ans[i / 2] + i % 2);
//		}
//
//		return ans;
//	}
//
//	void QuickPrint(const std::vector<int>& nums)
//	{
//		for (auto num : nums)
//		{
//			std::cout << num << ",";
//		}
//		std::cout << std::endl;
//	}
//}
//
//using namespace Question_338;
//// Test the code using the examples
//int main()
//{
//	// Example 1
//	QuickPrint(CountBits(2));
//
//	// Example 2
//	QuickPrint(CountBits(5));
//}