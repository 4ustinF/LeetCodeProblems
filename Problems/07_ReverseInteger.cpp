//#include <iostream>
//#include <string>
//#include <algorithm> 
//
//// Question
///*
//	7. Reverse Interger - August 7th, 2023
//	Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
//
//	Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
//*/
//
//// Examples
///*
//	Example 1:
//	Input: x = 123
//	Output: 321
//	
//	Example 2:
//	Input: x = -123
//	Output: -321
//	
//	Example 3:
//	Input: x = 120
//	Output: 21
//*/
//
//// Constraints
///*
//	-2^31 <= x <= 2^31 - 1
//*/
//
//namespace Question_07
//{
//	int Reverse(int x) 
//	{
//		int reverse = 0;
//		const int upperLimit = INT_MAX / 10; // == 214748364
//		const int lowerLimit = INT_MIN / 10; // == -214748364
//
//		while (x != 0) 
//		{
//			if (reverse > upperLimit || reverse < lowerLimit)
//			{
//				return 0;
//			}
//
//			// (reverse * 10) shifts value over
//			// +
//			// (x % 10) gets the next reverse number
//			reverse = reverse * 10 + x % 10;
//			x /= 10;
//		}
//
//		return reverse;
//	}
//}
//
//using namespace Question_07;
//// Test the code using the examples
//int main()
//{
//	// Example 1 = 321
//	std::cout << Reverse(123) << std::endl;
//
//	// Example 2 = -321
//	std::cout << Reverse(-123) << std::endl;
//
//	// Example 3 = 21
//	std::cout << Reverse(120) << std::endl;
//
//	// Example 4 = 0
//	std::cout << Reverse(INT_MAX) << std::endl;
//
//	// Example 5 = 0
//	std::cout << Reverse(INT_MIN) << std::endl;
//}