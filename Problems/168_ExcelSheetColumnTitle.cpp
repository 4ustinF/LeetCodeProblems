//#include <iostream>
//#include <string>
//
//// Question
///*
//	168. Excel Sheet Column Title - August 22nd, 2023
//	Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.
//
//	For example:
//	
//	A -> 1
//	B -> 2
//	C -> 3
//	...
//	Z -> 26
//	AA -> 27
//	AB -> 28
//	...
//*/
//
//// Examples
///*
//	Example 1:
//	
//	Input: columnNumber = 1
//	Output: "A"
//	Example 2:
//	
//	Input: columnNumber = 28
//	Output: "AB"
//	Example 3:
//	
//	Input: columnNumber = 701
//	Output: "ZY"
//*/
//
//// Constraints
///*
//	1 <= columnNumber <= 2^31 - 1
//*/
//
//namespace Question_168
//{
//	std::string ConvertToTitle(int columnNumber) 
//	{
//		std::string ans;
//
//		while (columnNumber != 0) 
//		{
//			columnNumber--;
//
//			// Get the last character and append it at the end of string.
//			ans += static_cast<char>((columnNumber) % 26 + 'A');
//			columnNumber = (columnNumber) / 26;
//		}
//
//		// Reverse it, as we appended characters in reverse order.
//		std::reverse(ans.begin(), ans.end());
//		return ans;
//	}
//}
//
//using namespace Question_168;
//// Test the code using the examples
//int main()
//{
//	// Example 1 = A
//	std::cout << ConvertToTitle(1) << std::endl;
//
//	// Example 2 = AB
//	std::cout << ConvertToTitle(28) << std::endl;
//
//	// Example 3 = ZY
//	std::cout << ConvertToTitle(701) << std::endl;
//}