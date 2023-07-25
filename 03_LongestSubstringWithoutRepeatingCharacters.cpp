#include <iostream>
#include <string>
#include <unordered_map>

// Question
/*
	3. Longest Substring Without Repeating Characters - July 25th, 2023
	Given a string s, find the length of the longest substring without repeating characters.
*/

// Examples
/*
	Example 1:
	Input: s = "abcabcbb"
	Output: 3
	Explanation: The answer is "abc", with the length of 3.
	
	Example 2:
	Input: s = "bbbbb"
	Output: 1
	Explanation: The answer is "b", with the length of 1.
	
	Example 3:
	Input: s = "pwwkew"
	Output: 3
	Explanation: The answer is "wke", with the length of 3.
	Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

// Constraints
/*
	0 <= s.length <= 5 * 104
	s consists of English letters, digits, symbols and spaces.
*/

namespace Question_003
{
	int LengthOfLongestSubstring(std::string s) 
	{
		const int stringLength = s.length();
		if (stringLength == 0 || stringLength == 1)
		{
			return stringLength;
		}

		int highestCount = 0;
		int count = 0;
		std::unordered_map<char, int> map;

		for (int i = 0; i < stringLength; ++i)
		{
			if (map.find(s[i]) == map.end()) // Not in the word yet
			{
				map.insert(std::make_pair(s[i], i));
				highestCount = std::max(highestCount, ++count);
			}
			else // Already in the word
			{
				// backtrack a start forming new word
				i -= count;
				count = 0;
				map.clear();
			}
		}

		return highestCount;
	}

	void DisplayLength(std::string s)
	{
		std::cout << s << " Length: " << LengthOfLongestSubstring(s) << std::endl;
	}
}

//using namespace Question_003;
//// Test the code using the examples
//int main()
//{
//	// Example 1
//	DisplayLength("abcabcbb");
//	
//	// Example 2
//	DisplayLength("bbbbb");
//	
//	// Example 3
//	DisplayLength("pwwkew");
//
//	// Example 4
//	DisplayLength("dvdf");
//}