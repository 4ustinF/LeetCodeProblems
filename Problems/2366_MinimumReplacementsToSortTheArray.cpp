//#include <iostream>
//#include <vector>
//
//// Question
///*
//	2366. Minimum Replacements to Sort the Array - August 30th, 2023
//	You are given a 0-indexed integer array nums. In one operation you can replace any element of the array with any two elements that sum to it.
//
//	For example, consider nums = [5,6,7]. In one operation, we can replace nums[1] with 2 and 4 and convert nums to [5,2,4,7].
//	Return the minimum number of operations to make an array that is sorted in non-decreasing order.
//*/
//
//// Examples
///*
//	Example 1:
//	Input: nums = [3,9,3]
//	Output: 2
//	Explanation: Here are the steps to sort the array in non-decreasing order:
//	- From [3,9,3], replace the 9 with 3 and 6 so the array becomes [3,3,6,3]
//	- From [3,3,6,3], replace the 6 with 3 and 3 so the array becomes [3,3,3,3,3]
//	There are 2 steps to sort the array in non-decreasing order. Therefore, we return 2.
//	
//	Example 2:
//	Input: nums = [1,2,3,4,5]
//	Output: 0
//	Explanation: The array is already in non-decreasing order. Therefore, we return 0. 
//*/
//
//// Constraints
///*
//	1 <= nums.length <= 10^5
//	1 <= nums[i] <= 10^9
//*/
//
//namespace Question_2366
//{
//	long long MinimumReplacement(std::vector<int>& nums) 
//	{
//		long long answer = 0;
//		const int size = static_cast<int>(nums.size());
//
//		// Start from the second last element, as the last one is always sorted.
//		for (int i = size - 2; i >= 0; --i) 
//		{
//			// No need to break if they are already in order.
//			if (nums[i] <= nums[i + 1]) 
//			{
//				continue;
//			}
//
//			// Count how many elements are made from breaking nums[i].
//			const long long numElements = static_cast<long long>(ceil((nums[i] + nums[i + 1] - 1LL) / (nums[i + 1])));
//
//			// It requires numElements - 1 replacement operations.
//			answer += numElements - 1;
//
//			// Maximize nums[i] after replacement.
//			nums[i] = nums[i] / static_cast<int>(numElements);
//		}
//
//		return answer;
//	}
//}
//
//using namespace Question_2366;
//// Test the code using the examples
//int main()
//{
//	// Example 1
//	std::vector<int> list1 = {3, 9, 3};
//	std::cout << MinimumReplacement(list1) << std::endl;
//
//	// Example 2
//	std::vector<int> list2 = { 1, 2, 3, 4, 5 };
//	std::cout << MinimumReplacement(list2) << std::endl;
//}