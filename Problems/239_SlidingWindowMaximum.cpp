//#include <iostream>
//#include <vector>
//#include <queue>
//
//// Question
///*
//	239. Sliding Window Maximum - August 16th, 2023
//	You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
//
//	Return the max sliding window.
//*/
//
//// Examples
///*
//	Example 1:
//	Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
//	Output: [3,3,5,5,6,7]
//	Explanation:
//	Window position                Max
//	---------------               -----
//	[1  3  -1] -3  5  3  6  7       3
//	 1 [3  -1  -3] 5  3  6  7       3
//	 1  3 [-1  -3  5] 3  6  7       5
//	 1  3  -1 [-3  5  3] 6  7       5
//	 1  3  -1  -3 [5  3  6] 7       6
//	 1  3  -1  -3  5 [3  6  7]      7
//
//	Example 2:
//	Input: nums = [1], k = 1
//	Output: [1]
//*/
//
//// Constraints
///*
//	1 <= nums.length <= 10^5
//	-10^4 <= nums[i] <= 10^4
//	1 <= k <= nums.length
//*/
//
//namespace Question_239
//{
//	std::vector<int> MaxSlidingWindow(std::vector<int>& nums, int k)
//	{
//		const int size = static_cast<int>(nums.size());
//		const int lesserK = k - 1;
//
//		std::priority_queue<std::pair<int, int>> priorityQueue;
//		std::vector<int> maxSlidingWindow;
//
//		for (int i = 0; i < lesserK; ++i)
//		{
//			priorityQueue.push({ nums[i], i });
//		}
//
//		for (int i = lesserK; i < size; ++i)
//		{
//			priorityQueue.push({ nums[i], i });
//
//			while (i - priorityQueue.top().second >= k)
//			{
//				priorityQueue.pop();
//			}
//			maxSlidingWindow.push_back(priorityQueue.top().first);
//		}
//
//		return maxSlidingWindow;
//	}
//
//	void QuickPrint(const std::vector<int>& nums)
//	{
//		for (auto num : nums)
//		{
//			std::cout << num << ", ";
//		}
//		std::cout << std::endl;
//	}
//}
//
//using namespace Question_239;
//// Test the code using the examples
//int main()
//{
//	// Example 1 = [3,3,5,5,6,7]
//	std::vector<int> list1 = { 1,3,-1,-3,5,3,6,7 };
//	QuickPrint(MaxSlidingWindow(list1, 3));
//
//	// Example 2 = [1]
//	std::vector<int> list2 = { 1 };
//	QuickPrint(MaxSlidingWindow(list2, 1));
//}