//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//// Question
///*
//	81. Search in Rotated Sorted Array II - August 10th, 2023
//	There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).
//
//	Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].
//
//	Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.
//
//	You must decrease the overall operation steps as much as possible.
//*/
//
//// Examples
///*
//	Example 1:
//	Input: nums = [2,5,6,0,0,1,2], target = 0
//	Output: true
//
//	Example 2:
//	Input: nums = [2,5,6,0,0,1,2], target = 3
//	Output: false
//*/
//
//// Constraints
///*
//	1 <= nums.length <= 5000
//	-10^4 <= nums[i] <= 10^4
//	nums is guaranteed to be rotated at some pivot.
//	-10^4 <= target <= 10^4
//*/
//
//// 4ms for linear search
//
//namespace Question_81
//{
//	bool Search(std::vector<int>& nums, int target)
//	{
//		std::sort(nums.begin(), nums.end());
//
//		int leftIndex = 0;
//		int rightIndex = static_cast<int>(nums.size()) - 1;
//
//		while (leftIndex < rightIndex)
//		{
//			const int midIndex = (leftIndex + rightIndex) / 2;
//
//			if (target > nums[midIndex])
//			{
//				leftIndex = midIndex + 1;
//			}
//			else
//			{
//				rightIndex = midIndex;
//			}
//		}
//
//		return nums[leftIndex] == target;
//	}
//}
//
//using namespace Question_81;
//// Test the code using the examples
//int main()
//{
//	// Example 1
//	std::vector<int> list1 = { 2,5,6,0,0,1,2 };
//	std::cout << (Search(list1, 0) ? "true" : "false") << std::endl;
//
//	// Example 2
//	std::vector<int> list2 = { 2,5,6,0,0,1,2 };
//	std::cout << (Search(list2, 3) ? "true" : "false") << std::endl;
//}