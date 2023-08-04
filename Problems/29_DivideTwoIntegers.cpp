//#include <iostream>
//
//// Question
///*
//	29. Divide Two Integers - July 31th, 2023
//	Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.
//
//	The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.
//	
//	Return the quotient after dividing dividend by divisor.
//	
//	Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231
//*/
//
//// Examples
///*
//	Example 1:
//	Input: dividend = 10, divisor = 3
//	Output: 3
//	Explanation: 10/3 = 3.33333.. which is truncated to 3.
//	
//	Example 2:
//	Input: dividend = 7, divisor = -3
//	Output: -2
//	Explanation: 7/-3 = -2.33333.. which is truncated to -2.
//*/
//
//// Constraints
///*
//	-2^31 <= dividend, divisor <= 2^31 - 1
//	divisor != 0
//*/
//
//namespace Question_29
//{
//	// Time complexity : O(a/b) 
//	// Auxiliary space : O(1)
//	int DivideWithSubtraction(int dividend, int divisor)
//	{
//		if (dividend == 0 || divisor == 0)
//		{
//			return 0;
//		}
//
//		const int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
//
//		// Make both divisor and dividend positive
//		dividend = abs(dividend);
//		divisor = abs(divisor);
//
//		// Initialize the quotient
//		int quotient = 0;
//		while (dividend >= divisor) 
//		{
//			dividend -= divisor;
//			++quotient;
//		}
//
//		// Return the value of quotient with the appropriate sign.
//		return quotient * sign;
//	}
//
//	// Time Complexity: O(1) as the time taken to perform the division is constant.
//	// Space Complexity : O(1) as no extra space is required.
//	int divide(int dividend, int divisor) 
//	{
//		if (dividend == 0)
//		{
//			return 0;
//		}
//
//		const int sign = (dividend < 0) ^ (divisor < 0);
//
//		dividend = abs(dividend);
//		divisor = abs(divisor);
//		if (divisor == 1)
//		{
//			return ((sign == 0) ? dividend : -dividend);
//		}
//
//		// log() : function used to get the logarithmic value of the entered value [Gives the natural log of the entered number]
//		// exp() : Return the e^(entered value)
//		const int ans = static_cast<int>(exp(log(dividend) - log(divisor)) + 0.0000000001);
//		/*
//		 adding 0.0000000001 to compensate for the precision errors
//		 like for a = 18 and b = -6,
//		 result after exponentiation will be 2.999999999...
//		 adding 0.0000000001, sets it right
//		*/
//		return ((sign == 0) ? ans : -ans);
//	}
//}
//
//using namespace Question_29;
//// Test the code using the examples
//int main()
//{
//	// Example 1 = 3
//	std::cout << divide(10, 3) << std::endl;
//
//	// Example 2 = -2
//	std::cout << divide(7, -3) << std::endl;
//
//	// Example 3 = 5
//	std::cout << divide(-10, -2) << std::endl;
//
//	// Example 4 = 0
//	std::cout << divide(0, 2) << std::endl;
//}