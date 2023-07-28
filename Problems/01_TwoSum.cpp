//#include <iostream>
//#include <vector>
//#include <unordered_map>
//
//// Question
///*
//	1. Two Sum - July 22nd, 2023
//	Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
//	You may assume that each input would have exactly one solution, and you may not use the same element twice.
//	You can return the answer in any order.
//*/
//
//// Examples
///*
//	Example 1:
//	Input: nums = [2,7,11,15], target = 9
//	Output: [0,1]
//	Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
//
//	Example 2:
//	Input: nums = [3,2,4], target = 6
//	Output: [1,2]
//
//	Example 3:
//	Input: nums = [3,3], target = 6
//	Output: [0,1]
//*/
//
//// Constraints
///*
//	2 <= nums.length <= 104
//	-109 <= nums[i] <= 109
//	-109 <= target <= 109
//	Only one valid answer exists.
//*/
//
//namespace Question_001
//{
//	//// First Attempt
//	//std::vector<int> TwoSum(std::vector<int>& nums, int target)
//	//{
//	//	for (int i = 0; i < nums.size(); ++i)
//	//	{
//	//		for (int j = i + 1; j < nums.size(); ++j)
//	//		{
//	//			if (nums[i] + nums[j] == target)
//	//			{
//	//				std::cout << "[" << i << ", " << j << "]" << std::endl;
//	//				return { i, j };
//	//			}
//	//		}
//	//	}
//
//	//	std::cout << "Error: No sum found" << std::endl;
//	//	return { -1, -1 };
//	//}
//
//	// Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
//	std::vector<int> TwoSum(std::vector<int>& nums, int target)
//	{
//		std::unordered_map<int, int> map;
//		map.insert(std::make_pair(nums[0], 0));
//
//		for (int i = 1; i < nums.size(); ++i)
//		{
//			const int numToFind = target - nums[i];
//			const auto iter = map.find(numToFind);
//
//			if (iter != map.end())
//			{
//				std::cout << "[" << iter->second << ", " << i << "]" << std::endl;
//				return { iter->second, i };
//			}
//
//			map.insert(std::make_pair(nums[i], i));
//		}
//
//		std::cout << "Error: No sum found" << std::endl;
//		return { -1, -1 };
//	}
//}
//
//using namespace question_001;
//// test the code using the examples
//int main()
//{
//	std::vector<int> examplelist1 = { 2, 7, 11, 15 };
//	twosum(examplelist1, 9);
//
//	std::vector<int> examplelist2 = { 3, 2, 4 };
//	twosum(examplelist2, 6);
//
//	std::vector<int> examplelist3 = { 3, 3 };
//	twosum(examplelist3, 6);
//}