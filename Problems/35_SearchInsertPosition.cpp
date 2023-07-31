//#include <iostream>
//#include <vector>
//
//// Question
///*
//	35. Search Insert Position - July 25th, 2023
//	Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
//
//	You must write an algorithm with O(log n) runtime complexity.
//*/
//
//// Examples
///*
//	Example 1:
//	Input: nums = [1,3,5,6], target = 5
//	Output: 2
//	
//	Example 2:
//	Input: nums = [1,3,5,6], target = 2
//	Output: 1
//	
//	Example 3:
//	Input: nums = [1,3,5,6], target = 7
//	Output: 4
//*/
//
//// Constraints
///*
//	1 <= nums.length <= 104
//	-10^4 <= nums[i] <= 10^4
//	nums contains distinct values sorted in ascending order.
//	-10^4 <= target <= 10^4
//*/
//
//namespace Question_35
//{
//	int searchInsert(std::vector<int>& nums, int target) 
//	{
//		const int listSize = static_cast<int>(nums.size());
//		if (target > nums[listSize - 1])
//		{
//			return listSize;
//		}
//
//		int leftIndex = 0;
//		int rightIndex = listSize - 1;
//		int midIndex = 0;
//
//		while (leftIndex < rightIndex)
//		{
//			midIndex = (leftIndex + rightIndex) / 2;
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
//		return leftIndex;
//	}
//}
//
//using namespace Question_35;
//// Test the code using the examples
//int main()
//{
//	// Example 1 = 2
//	std::vector<int> list = {1, 3, 5, 6};
//	std::cout << searchInsert(list, 5) << std::endl;
//
//	// Example 2 = 1
//	std::cout << searchInsert(list, 2) << std::endl;
//
//	// Example 3 = 4
//	std::cout << searchInsert(list, 7) << std::endl;
//}