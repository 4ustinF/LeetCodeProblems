//#include <iostream>
//#include <vector>
//
//// Question
///*
//	11. Container With Most Water - July 29th, 2023
//	You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
//
//	Find two lines that together with the x-axis form a container, such that the container contains the most water.
//
//	Return the maximum amount of water a container can store.
//
//	Notice that you may not slant the container.
//*/
//
//// Examples
///*
//	Example 1:
//	Input: height = [1,8,6,2,5,4,8,3,7]
//	Output: 49
//	Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
//
//	Example 2:
//	Input: height = [1,1]
//	Output: 1
//*/
//
//// Constraints
///*
//	n == height.length
//	2 <= n <= 105
//	0 <= height[i] <= 104
//*/
//
//namespace Question_11
//{
//	int MaxArea(std::vector<int>& height)
//	{
//		int leftIndex = 0;
//		int rightIndex = static_cast<int>(height.size()) - 1;
//		int maximumArea = 0;
//
//		while (leftIndex < rightIndex)
//		{
//			// Calculate area and set maxArea if its bigger
//			const int area = std::min(height[leftIndex], height[rightIndex]) * (rightIndex - leftIndex);
//			maximumArea = std::max(maximumArea, area);
//
//			// Shift pointers
//			height[leftIndex] <= height[rightIndex] ? leftIndex++ : rightIndex--;
//		}
//
//		return maximumArea;
//	}
//}
//
//using namespace Question_11;
//// Test the code using the examples
//int main()
//{
//	// Example 1
//	std::vector<int> list1 = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
//	std::cout << MaxArea(list1) << std::endl;
//
//	// Example 2
//	std::vector<int> list2 = { 1, 1 };
//	std::cout << MaxArea(list2) << std::endl;
//}