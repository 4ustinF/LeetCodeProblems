//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//// Question
///*
//	646. Maximum Length of Pair Chain - August 26th, 2023
//	You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.
//
//	A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.
//	
//	Return the length longest chain which can be formed.
//	
//	You do not need to use up all the given intervals. You can select pairs in any order.
//*/
//
//// Examples
///*
//	Example 1:
//	Input: pairs = [[1,2],[2,3],[3,4]]
//	Output: 2
//	Explanation: The longest chain is [1,2] -> [3,4].
//	
//	Example 2:
//	Input: pairs = [[1,2],[7,8],[4,5]]
//	Output: 3
//	Explanation: The longest chain is [1,2] -> [4,5] -> [7,8]
//*/
//
//// Constraints
///*
//	n == pairs.length
//	1 <= n <= 1000
//	-1000 <= lefti < righti <= 1000
//*/
//
//namespace Question_646
//{
//	int findLongestChain(std::vector<std::vector<int>>& pairs)
//	{
//		const int size = static_cast<int>(pairs.size());
//		std::sort(pairs.begin(), pairs.end());
//		std::vector<int> dp(size, 1);
//		int ans = 1;
//
//		for (int i = size - 1; i >= 0; --i)
//		{
//			for (int j = i + 1; j < size; ++j) 
//			{
//				if (pairs[i][1] < pairs[j][0]) 
//				{
//					dp[i] = std::max(dp[i], 1 + dp[j]);
//				}
//			}
//			ans = std::max(ans, dp[i]);
//		}
//		return ans;
//	}
//
//}
//
//using namespace Question_646;
//// Test the code using the examples
//int main()
//{
//	// Example 1 = 2
//	std::vector<std::vector<int>> list1 = { {1, 2}, {2, 3}, {3, 4} };
//	std::cout << findLongestChain(list1) << std::endl;
//
//	// Example 2 = 3
//	std::vector<std::vector<int>> list2 = { {1, 2}, {7, 8}, {4, 5} };
//	std::cout << findLongestChain(list2) << std::endl;
//
//	// Example 3 = 2
//	std::vector<std::vector<int>> list3 = { {1, 2}, {2, 5}, {2, 3}, {3, 4} };
//	std::cout << findLongestChain(list3) << std::endl;
//
//}