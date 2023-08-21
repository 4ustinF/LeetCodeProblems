//#include <iostream>
//#include <string>
//
//// Question
///*
//	459. Repeated Substring Pattern - August 21st, 2023
//	Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.
//*/
//
//// Examples
///*
//	Example 1:
//	Input: s = "abab"
//	Output: true
//	Explanation: It is the substring "ab" twice.
//	
//	Example 2:
//	Input: s = "aba"
//	Output: false
//	
//	Example 3:
//	Input: s = "abcabcabcabc"
//	Output: true
//	Explanation: It is the substring "abc" four times or the substring "abcabc" twice.
//*/
//
//// Constraints
///*
//	1 <= s.length <= 104
//	s consists of lowercase English letters.
//*/
//
//namespace Question_459
//{
//	bool RepeatedSubstringPattern(std::string s) 
//	{
//		const std::string t = s + s;
//		return t.substr(1, t.size() - 2).find(s) != -1;
//	}
//}
//
//using namespace Question_459;
//// Test the code using the examples
//int main()
//{
//	// Example 1 = true
//	std::cout << RepeatedSubstringPattern("abab") << std::endl;
//
//	// Example 2 = false
//	std::cout << RepeatedSubstringPattern("aba") << std::endl;
//
//	// Example 3 = true 
//	std::cout << RepeatedSubstringPattern("abcabcabcabc") << std::endl;
//
//	// Example 4 = true 
//	std::cout << RepeatedSubstringPattern("ababab") << std::endl;
//
//	// Example 5 = false 
//	std::cout << RepeatedSubstringPattern("sosbob") << std::endl;
//}