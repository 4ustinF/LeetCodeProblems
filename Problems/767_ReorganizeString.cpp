//#include <iostream>
//#include <string>
//#include <vector>
//#include <queue>
//
//// Question
///*
//	767. Reorganize String - August 23rd, 2023
//	Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
//
//	Return any possible rearrangement of s or return "" if not possible.
//*/
//
//// Examples
///*
//	Example 1:
//	Input: s = "aab"
//	Output: "aba"
//	
//	Example 2:
//	Input: s = "aaab"
//	Output: ""
//*/
//
//// Constraints
///*
//	1 <= s.length <= 500
//	s consists of lowercase English letters.
//*/
//
//namespace Question_767
//{
//	std::string ReorganizeString(std::string s) 
//	{
//        std::vector<int> charCounts(26, 0);
//        for (char c : s) 
//        {
//            charCounts[c - 'a'] += 1;
//        }
//
//        // Max heap ordered by character counts
//        std::priority_queue<std::vector<int>> pq;
//        for (int i = 0; i < 26; ++i)
//        {
//            if (charCounts[i] > 0) 
//            {
//                pq.push(std::vector<int>{charCounts[i], i + 'a'});
//            }
//        }
//
//        std::string result;
//        while (!pq.empty()) 
//        {
//            auto first = pq.top();
//            pq.pop();
//
//            if (result.empty() || first[1] != result.back()) 
//            {
//                result += static_cast<char>(first[1]);
//                if (--first[0] > 0) 
//                {
//                    pq.push(first);
//                }
//                continue;
//            }
//
//            if (pq.empty())
//            {
//                return "";
//            }
//
//            auto second = pq.top();
//            pq.pop();
//            result += static_cast<char>(second[1]);
//
//            if (--second[0] > 0)
//            {
//                pq.push(std::move(second));
//            }
//
//            pq.push(std::move(first));
//        }
//
//        return result;
//	}
//}
//
//using namespace Question_767;
//// Test the code using the examples
//int main()
//{
//	// Example 1 = "aba"
//	std::cout << ReorganizeString("aab") << std::endl;
//
//	// Example 2 = ""
//	std::cout << ReorganizeString("aaab") << std::endl;
//}