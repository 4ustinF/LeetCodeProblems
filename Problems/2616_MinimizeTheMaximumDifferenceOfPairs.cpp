//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//// Question
///*
//	2616. Minimize the Maximum Difference of Pairs - August 9th, 2023
//	You are given a 0-indexed integer array nums and an integer p. Find p pairs of indices of nums such that the maximum difference amongst all the pairs is minimized. Also, ensure no index appears more than once amongst the p pairs.
//
//	Note that for a pair of elements at the index i and j, the difference of this pair is |nums[i] - nums[j]|, where |x| represents the absolute value of x.
//
//	Return the minimum maximum difference among all p pairs. We define the maximum of an empty set to be zero.
//*/
//
//// Examples
///*
//	Example 1:
//	Input: nums = [10,1,2,7,1,3], p = 2
//	Output: 1
//	Explanation: The first pair is formed from the indices 1 and 4, and the second pair is formed from the indices 2 and 5.
//	The maximum difference is max(|nums[1] - nums[4]|, |nums[2] - nums[5]|) = max(0, 1) = 1. Therefore, we return 1.
//
//	Example 2:
//	Input: nums = [4,2,1,2], p = 1
//	Output: 0
//	Explanation: Let the indices 1 and 3 form a pair. The difference of that pair is |2 - 2| = 0, which is the minimum we can attain.
//*/
//
//// Constraints
///*
//	1 <= nums.length <= 10^5
//	0 <= nums[i] <= 10^9
//	0 <= p <= (nums.length)/2
//*/
//
//namespace Question_2616
//{
//	// Find the number of valid pairs by greedy approach
//	int CountValidPairs(const std::vector<int>& nums, int threshold) 
//	{
//		int index = 0;
//		int count = 0;
//		const int lastIndex = static_cast<int>(nums.size()) - 1;
//
//		while (index < lastIndex)
//		{
//			// If a valid pair is found, skip both numbers.
//			if (nums[index + 1] - nums[index] <= threshold) 
//			{
//				count++;
//				index++;
//			}
//			index++;
//		}
//		return count;
//	}
//
//	int MinimizeMax(std::vector<int>& nums, int p)
//	{
//		std::sort(nums.begin(), nums.end());
//		const int size = static_cast<int>(nums.size());
//		int left = 0;
//		int right = nums[size - 1] - nums[0];
//
//		while (left < right) 
//		{
//			const int mid = left + (right - left) / 2;
//
//			// If there are enough pairs, look for a smaller threshold.
//			// Otherwise, look for a larger threshold.
//			if (CountValidPairs(nums, mid) >= p) 
//			{
//				right = mid;
//			}
//			else {
//				left = mid + 1;
//			}
//		}
//		return left;
//	}
//}
//
//using namespace Question_2616;
//// Test the code using the examples
//int main()
//{
//	// Example 1
//	std::vector<int> list1 = { 10, 1, 2, 7, 1, 3 };
//	std::cout << MinimizeMax(list1, 2) << std::endl;
//
//	// Example 2
//	std::vector<int> list2 = { 4, 2, 1, 2 };
//	std::cout << MinimizeMax(list2, 1) << std::endl;
//}