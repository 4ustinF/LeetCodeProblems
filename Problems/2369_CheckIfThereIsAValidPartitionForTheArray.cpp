//#include <iostream>
//#include <vector>
//
//// Question
///*
//	2369. Check if There is a Valid Partition For The Array - August 13th, 2023
//	You are given a 0-indexed integer array nums. You have to partition the array into one or more contiguous subarrays.
//
//	We call a partition of the array valid if each of the obtained subarrays satisfies one of the following conditions:
//
//	The subarray consists of exactly 2 equal elements. For example, the subarray [2,2] is good.
//	The subarray consists of exactly 3 equal elements. For example, the subarray [4,4,4] is good.
//	The subarray consists of exactly 3 consecutive increasing elements, that is, the difference between adjacent elements is 1. For example, the subarray [3,4,5] is good, but the subarray [1,3,5] is not.
//	Return true if the array has at least one valid partition. Otherwise, return false.
//*/
//
//// Examples
///*
//	Example 1:
//	Input: nums = [4,4,4,5,6]
//	Output: true
//	Explanation: The array can be partitioned into the subarrays [4,4] and [4,5,6].
//	This partition is valid, so we return true.
//
//	Example 2:
//	Input: nums = [1,1,1,2]
//	Output: false
//	Explanation: There is no valid partition for this array.
//*/
//
//// Constraints
///*
//	2 <= nums.length <= 10^5
//	1 <= nums[i] <= 10^6
//*/
//
///*
//	4, 4, 4, 5, 6
//	size = 5
//	dp = true, false, true
//
//	// i = 2; i < 5
//	dp = false, true, true
//*/
//
//namespace Question_2369
//{
//	bool ValidPartition(std::vector<int>& nums)
//	{
//		const int size = static_cast<int>(nums.size());
//		std::vector<bool> dp = { true, false, nums[0] == nums[1] };
//
//		for (int i = 2; i < size; ++i) 
//		{
//			const bool current_dp = (nums[i] == nums[i - 1] && dp[1]) ||					// The subarray consists of exactly 2 equal elements.
//				(nums[i] == nums[i - 1] && nums[i] == nums[i - 2] && dp[0]) ||				// The subarray consists of exactly 3 equal elements.
//				(nums[i] - nums[i - 1] == 1 && nums[i - 1] - nums[i - 2] == 1 && dp[0]);	// The subarray consists of exactly 3 consecutive increasing elements, that is, the difference between adjacent elements is 1.
//
//			// Shift
//			dp[0] = dp[1];
//			dp[1] = dp[2];
//			dp[2] = current_dp;
//		}
//
//		// If we make it to the end without any fault this will return true
//		return dp[2];
//	}
//}
//
//using namespace Question_2369;
//// Test the code using the examples
//int main()
//{
//	// Example 1 = true
//	std::vector<int> list1 = { 4, 4, 4, 5, 6 };
//	std::cout << ValidPartition(list1) << std::endl;
//
//	// Example 1 = true
//	std::vector<int> list2= { 1, 1, 1, 2};
//	std::cout << ValidPartition(list2) << std::endl;
//}