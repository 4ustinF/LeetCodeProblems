//#include <iostream>
//#include <string>
//#include <vector>
//
//// Question
///*
//	9. Palindrome Number - July 28th, 2023
//	Given an integer x, return true if x is a palindrome, and false otherwise.
//*/
//
//// Examples
///*
//	Example 1:
//	Input: x = 121
//	Output: true
//	Explanation: 121 reads as 121 from left to right and from right to left.
//	
//	Example 2:
//	Input: x = -121
//	Output: false
//	Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
//	
//	Example 3:
//	Input: x = 10
//	Output: false
//	Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
//*/
//
//// Constraints
///*
//	-2^31 <= x <= 2^31 - 1
//*/
//
//// Follow up : Could you solve it without converting the integer to a string ?
//		// Ex. 16561
//		// Figure out how many digits are in it
//		// = 5
//
//		// Create a list to keep track of digits
//		// std::vector<int> nums;
//
//		// Get first digit by dividing by 10s
//		// (16561 / 10) * (5 - 1) = 1
//
//		// Get second digit looping through the nums list and multyplying that number subtracting each then by dividing by 10s
//		// ((16561 - 1 * 10^5) / 10) * (5 - 1) = 1
//
//		// and so on...
//
//namespace Question_01
//{
//	// Converting to string
//	bool IsPalindrome(int x) 
//	{
//		// If the number is a negative it cannot be a Palindrome (e.g -121 = 121-)
//		if (x < 0)
//		{
//			return false;
//		}
//
//		const std::string num = std::to_string(x);
//		const int numSize = static_cast<int>(num.size());
//
//		for (int i = 0; i < numSize; ++i)
//		{
//			if (num[i] != num[numSize - i - 1])
//			{
//				return false;
//			}
//		}
//
//		return true;
//	}
//}
//
//using namespace Question_01;
//// Test the code using the examples
//int main()
//{
//	// Example 1 = True
//	std::cout << IsPalindrome(121) << std::endl;
//
//	// Example 2 = false
//	std::cout << IsPalindrome(-121) << std::endl;
//
//	// Example 3 = false
//	std::cout << IsPalindrome(10) << std::endl;
//
//	// Example 4 = true
//	std::cout << IsPalindrome(1661) << std::endl;
//
//	// Example 4 = true
//	std::cout << IsPalindrome(16561) << std::endl;
//}