//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//// Question
///*
//	4. Median of Two Sorted Arrays - July 25th, 2023
//	Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
//
//	The overall run time complexity should be O(log (m+n)).
//*/
//
//// Examples
///*
//	Example 1:
//	Input: nums1 = [1,3], nums2 = [2]
//	Output: 2.00000
//	Explanation: merged array = [1,2,3] and median is 2.
//
//	Example 2:
//	Input: nums1 = [1,2], nums2 = [3,4]
//	Output: 2.50000
//	Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
//*/
//
//// Constraints
///*
//	nums1.length == m
//	nums2.length == n
//	0 <= m <= 1000
//	0 <= n <= 1000
//	1 <= m + n <= 2000
//	-10^6 <= nums1[i], nums2[i] <= 10^6
//*/
//
//namespace Question_04
//{
//	double FindMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
//	{
//		// Append the two list into one (Create a copy list if you dont want the data modified)
//		nums1.insert(nums1.end(), nums2.begin(), nums2.end());
//
//		// Sort the new list 
//		std::sort(nums1.begin(), nums1.end());
//
//		const int listSize = static_cast<int>(nums1.size());
//		const int middleIndex = listSize / 2;
//
//		// If size == odd number then the median is the number in the middle of the list
//		if (listSize % 2 == 1)
//		{
//			return static_cast<double>(nums1[middleIndex]);
//		}
//
//		// If size == even add the two numbers in the middle and divide them by 2
//		return static_cast<double>(nums1[middleIndex] + nums1[middleIndex - 1]) * 0.5;
//	}
//}
//
//using namespace Question_04;
//// Test the code using the examples
//int main()
//{
//	// Example 1
//	std::vector<int> list1 = { 1, 3 };
//	std::vector<int> list2 = { 2 };
//	std::cout << "Median:" << FindMedianSortedArrays(list1, list2) << std::endl;
//
//	// Example 1
//	std::vector<int> list3 = { 1, 2 };
//	std::vector<int> list4 = { 3, 4 };
//	std::cout << "Median:" << FindMedianSortedArrays(list3, list4) << std::endl;
//}