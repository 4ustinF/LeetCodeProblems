//#include <iostream>
//#include <vector>
//
//// Question
///*
//	518. Coin Change II - August 11th, 2023
//	You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
//
//	Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
//
//	You may assume that you have an infinite number of each kind of coin.
//
//	The answer is guaranteed to fit into a signed 32-bit integer.
//*/
//
//// Examples
///*
//	Example 1:
//	Input: amount = 5, coins = [1,2,5]
//	Output: 4
//	Explanation: there are four ways to make up the amount:
//	5=5
//	5=2+2+1
//	5=2+1+1+1
//	5=1+1+1+1+1
//
//	Example 2:
//	Input: amount = 3, coins = [2]
//	Output: 0
//	Explanation: the amount of 3 cannot be made up just with coins of 2.
//
//	Example 3:
//	Input: amount = 10, coins = [10]
//	Output: 1
//*/
//
//// Constraints
///*
//	1 <= coins.length <= 300
//	1 <= coins[i] <= 5000
//	All the values of coins are unique.
//	0 <= amount <= 5000
//*/
//
//namespace Question_518
//{
//	int Change(int amount, std::vector<int>& coins)
//	{
//		const int size = static_cast<int>(coins.size());
//		std::vector<std::vector<int>> dp(size + 1, std::vector<int>(amount + 1));
//		for (int i = 0; i < size; i++) 
//		{
//			dp[i][0] = 1;
//		}
//
//		for (int i = size - 1; i >= 0; --i) 
//		{
//			for (int j = 1; j <= amount; ++j) 
//			{
//				if (coins[i] > j) 
//				{
//					dp[i][j] = dp[i + 1][j];
//				}
//				else 
//				{
//					dp[i][j] = dp[i + 1][j] + dp[i][j - coins[i]];
//				}
//			}
//		}
//
//		return dp[0][amount];
//	}
//}
//
//using namespace Question_518;
//// Test the code using the examples
//int main()
//{
//	// Example 1 = 4
//	std::vector<int> list1 = { 1, 2, 5 };
//	std::cout << Change(5, list1) << std::endl;
//
//	// Example 2 = 0
//	std::vector<int> list2 = { 2 };
//	std::cout << Change(3, list2) << std::endl;
//
//	// Example 3 = 1
//	std::vector<int> list3 = { 10 };
//	std::cout << Change(10, list3) << std::endl;
//
//}