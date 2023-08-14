//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <queue>
//
//// Question
///*
//	215. Kth Largest Element in an Array - August 14th, 2023
//	Given an integer array nums and an integer k, return the kth largest element in the array.
//
//	Note that it is the kth largest element in the sorted order, not the kth distinct element.
//
//	Can you solve it without sorting?
//*/
//
//// Examples
///*
//	Example 1:
//	Input: nums = [3,2,1,5,6,4], k = 2
//	Output: 5
//
//	Example 2:
//	Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
//	Output: 4
//*/
//
//// Constraints
///*
//	1 <= k <= nums.length <= 105
//	-10^4 <= nums[i] <= 10^4
//*/
//
//namespace Question_215
//{
//	int FindKthLargest(std::vector<int>& nums, int k)
//	{
//		std::sort(nums.begin(), nums.end());
//		return nums[nums.size() - k];
//	}
//
//	//// Without sorting
//	//int FindKthLargest(std::vector<int>& nums, int k)
//	//{
//	//	std::priority_queue<int> heap;
//	//	//A priority queue is a container adaptor that provides constant time lookup of the largest(by default) element, at the expense of logarithmic insertion and extraction.
//
//	//	// We inverse the num so the lower numbers become the bigger numbers so they can be popped out of the queue
//	//	for (int num : nums) 
//	//	{
//	//		heap.push(-num);
//	//		if (heap.size() > k) 
//	//		{
//	//			heap.pop();
//	//		}
//	//	}
//
//	//	return -heap.top();
//	//}
//}
//
//using namespace Question_215;
//// Test the code using the examples
//int main()
//{
//	// Example 1 = 5
//	std::vector<int> list1 = { 3, 2, 1, 5, 6, 4 };
//	//std::cout << FindKthLargest(list1, 2) << std::endl;
//
//	// Example 2 = 4
//	std::vector<int> list2 = { 3, 2, 3, 1, 2, 4, 5, 5, 6 };
//	//std::cout << FindKthLargest(list2, 4) << std::endl;
//
//	// Example 3 = 6
//	std::vector<int> list3 = { 0, 1, 1, 1, 6, 1, 1, 1, 1, 1, 7, 2, 1, 1, 1, 6 };
//	std::cout << FindKthLargest(list3, 3) << std::endl;
//}