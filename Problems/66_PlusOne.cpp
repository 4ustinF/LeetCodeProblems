//#include <iostream>
//#include <vector>
//
//// Question
///*
//	66. Plus One - August 8th, 2023
//	You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
//
//	Increment the large integer by one and return the resulting array of digits.
//*/
//
//// Examples
///*
//	Example 1:
//	Input: digits = [1,2,3]
//	Output: [1,2,4]
//	Explanation: The array represents the integer 123.
//	Incrementing by one gives 123 + 1 = 124.
//	Thus, the result should be [1,2,4].
//
//	Example 2:
//	Input: digits = [4,3,2,1]
//	Output: [4,3,2,2]
//	Explanation: The array represents the integer 4321.
//	Incrementing by one gives 4321 + 1 = 4322.
//	Thus, the result should be [4,3,2,2].
//
//	Example 3:
//	Input: digits = [9]
//	Output: [1,0]
//	Explanation: The array represents the integer 9.
//	Incrementing by one gives 9 + 1 = 10.
//	Thus, the result should be [1,0].
//*/
//
//// Constraints
///*
//	1 <= digits.length <= 100
//	0 <= digits[i] <= 9
//	digits does not contain any leading 0's.
//*/
//
//namespace Question_66
//{
//	std::vector<int> PlusOne(std::vector<int>& digits)
//	{
//		const int lastIndex = static_cast<int>(digits.size()) - 1;
//		digits[lastIndex]++;
//
//		for (int i = lastIndex; i >= 0; --i) 
//		{
//			if (digits[i] != 10) 
//			{
//				return digits;
//			}
//
//			digits[i] = 0;
//
//			if (i != 0) // If we are not at the end increase the next value
//			{
//				digits[i - 1]++;
//			}
//			else // If we are at the end then expand
//			{
//				digits.push_back(0);
//				digits[i] = 1;
//			}
//		}
//		return digits;
//	}
//
//	void PrintAnswer(const std::vector<int>& digits)
//	{
//		const int lastIndex = static_cast<int>(digits.size()) - 1;
//
//		std::cout << "[";
//		for (int i = 0; i < lastIndex; ++i)
//		{
//			std::cout << digits[i] << ", ";
//		}
//		std::cout << digits[lastIndex] << "]" << std::endl;
//	}
//}
//
//using namespace Question_66;
//// Test the code using the examples
//int main()
//{
//	// Example 1 = 1, 2, 4
//	std::vector<int> list1 = { 1, 2, 3 };
//	PrintAnswer(PlusOne(list1));
//
//	// Example 2 = 4322
//	std::vector<int> list2 = { 4, 3, 2, 1 };
//	PrintAnswer(PlusOne(list2));
//	
//	// Example 3 = 10
//	std::vector<int> list3 = { 9 };
//	PrintAnswer(PlusOne(list3));
//	
//	// Example 4 = 100
//	std::vector<int> list4 = { 9, 9 };
//	PrintAnswer(PlusOne(list4));
//
//	// Example 5 = 100
//	std::vector<int> list5 = { 9, 8, 9 };
//	PrintAnswer(PlusOne(list5));
//}