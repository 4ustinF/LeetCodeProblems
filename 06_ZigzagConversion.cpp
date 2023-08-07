//#include <iostream>
//#include <string>
//#include <vector>
//
//// Question
///*
//	6. Zigzag Conversion - August 6th, 2023
//	The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
//	(you may want to display this pattern in a fixed font for better legibility)
//	P   A   H   N
//	A P L S I I G
//	Y   I   R
//
//	And then read line by line: "PAHNAPLSIIGYIR"
//
//	Write the code that will take a string and make this conversion given a number of rows:
//
//	string convert(string s, int numRows);
//*/
//
//// Examples
///*
//	Example 0:
//	Input: s = "PAYPALISHIRING", numRows = 2
//	Output: "PYAIHRNAPLSIIG"
//	Explanation:
//	P Y A I H R N
//	A P L S I I G
//
//	Example 1:
//	Input: s = "PAYPALISHIRING", numRows = 3
//	Output: "PAHNAPLSIIGYIR"
//	Explanation:
//	P   A   H   N
//	A P L S I I G
//	Y   I   R
//
//	Example 2:
//	Input: s = "PAYPALISHIRING", numRows = 4
//	Output: "PINALSIGYAHRPI"
//	Explanation:
//	P     I    N
//	A   L S  I G
//	Y A   H R
//	P     I
//
//	Example 3:
//	Input: s = "A", numRows = 1
//	Output: "A"
//
//	3 = 1
//	4 = 2
//	5 = 3
//	6 = 4
//*/
//
//// Constraints
///*
//	1 <= s.length <= 1000
//	s consists of English letters (lower-case and upper-case), ',' and '.'.
//	1 <= numRows <= 1000
//*/
//
//namespace Question_06
//{
//	std::string Convert(std::string s, int numRows)
//	{
//		if (numRows <= 1)
//		{
//			return s;
//		}
//
//		const int rowFinalIndex = numRows - 1;
//		std::vector<std::string> list(numRows, "");
//		int currentLine = 0;
//		bool reachedEdge = true;
//
//		for (int i = 0; i < s.length(); ++i)
//		{
//			if (currentLine == 0 || currentLine == rowFinalIndex)
//			{
//				reachedEdge = !reachedEdge;
//			}
//
//			list[currentLine] += s[i];
//			currentLine += (reachedEdge ? -1 : 1);
//		}
//
//		std::string convertedResult;
//		for (int i = 0; i < numRows; ++i) 
//		{
//			convertedResult += list[i];
//		}
//		return convertedResult;
//	}
//
//	void CheckConversion(const std::string& s1, const std::string& s2)
//	{
//		std::cout << (s1.compare(s2) ? "False" : "True") << std::endl;
//	}
//}
//
//using namespace Question_06;
//// Test the code using the examples
//int main()
//{
//	// Example -1 = PAYPALISHIRING
//	CheckConversion(Convert("PAYPALISHIRING", 1), "PAYPALISHIRING");
//
//	// Example 0 = PYAIHRNAPLSIIG
//	CheckConversion(Convert("PAYPALISHIRING", 2), "PYAIHRNAPLSIIG");
//
//	// Example 1 = PAHNAPLSIIGYIR
//	CheckConversion(Convert("PAYPALISHIRING", 3), "PAHNAPLSIIGYIR");
//
//	// Example 2 = PINALSIGYAHRPI
//	CheckConversion(Convert("PAYPALISHIRING", 4), "PINALSIGYAHRPI");
//
//	// Example 3 = A
//	CheckConversion(Convert("A", 1), "A");
//}