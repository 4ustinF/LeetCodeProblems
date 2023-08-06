//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//// Question
///*
//	46. Permutations - August 6th, 2023
//	Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
//*/
//
//// Examples
///*
//	Example 1:
//	Input: nums = [1,2,3]
//	Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
//
//	Example 2:
//	Input: nums = [0,1]
//	Output: [[0,1],[1,0]]
//
//	Example 3:
//	Input: nums = [1]
//	Output: [[1]]
//*/
//
//// Constraints
///*
//	1 <= nums.length <= 6
//	-10 <= nums[i] <= 10
//	All the integers of nums are unique.
//*/
//
//namespace Question_46
//{
//	std::vector<std::vector<int>> Permute(std::vector<int>& nums)
//	{
//		std::vector<std::vector<int>> permutations;
//		do
//		{
//			std::vector<int> list;
//			list.reserve(nums.size());
//			for (auto num : nums)
//			{
//				list.push_back(std::move(num));
//			}
//			permutations.push_back(std::move(list));
//		} while (std::next_permutation(nums.begin(), nums.end()));
//
//		return permutations;
//	}
//
//	void PrintPermutations(const std::vector<std::vector<int>>& permutations)
//	{
//		for (const auto& nums : permutations)
//		{
//			for (auto num : nums)
//			{
//				std::cout << num << " ";
//			}
//			std::cout << "\n";
//		}
//	}
//}
//
//using namespace Question_46;
//// Test the code using the examples
//int main()
//{
//	//// Example 1
//	//std::vector<int> nums1 = { 1, 2, 3 };
//	//std::vector<std::vector<int>> perms1 = Permute(nums1);
//	//PrintPermutations(perms1);
//
//	// Example 4
//	std::vector<int> nums4 = { 0, -1, 1 };
//	std::vector<std::vector<int>> perms4 = Permute(nums4);
//	PrintPermutations(perms4);
//}