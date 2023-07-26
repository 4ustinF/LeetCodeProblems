#include <iostream>
#include <vector>

// Question
/*
	852. Peak Index in a Mountain Array - July 25th, 2023
	An array arr a mountain if the following properties hold:

	arr.length >= 3
	There exists some i with 0 < i < arr.length - 1 such that:
	arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
	arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
	Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

	You must solve it in O(log(arr.length)) time complexity.
*/

// Examples
/*
	Example 1:
	Input: arr = [0,1,0]
	Output: 1

	Example 2:
	Input: arr = [0,2,1,0]
	Output: 1

	Example 3:
	Input: arr = [0,10,5,2]
	Output: 1
*/

// Constraints
/*
	3 <= arr.length <= 10^5
	0 <= arr[i] <= 10^6
	arr is guaranteed to be a mountain array.
*/

namespace Question_852
{
	int PeakIndexInMountainArray(std::vector<int>& arr)
	{
		int leftIndex = 0;
		int rightIndex = static_cast<int>(arr.size()) - 1;
		int middleIndex = 0;

		while (leftIndex < rightIndex) 
		{
			middleIndex = (leftIndex + rightIndex) / 2;
			if (arr[middleIndex] < arr[middleIndex + 1])
			{
				leftIndex = middleIndex + 1;
			}
			else
			{
				rightIndex = middleIndex;
			}
		}
		return leftIndex;
	}
}

//using namespace Question_852;
//// Test the code using the examples
//int main()
//{
//	// Example 1
//	std::vector<int> arr1 = { 0, 1, 0 };
//	std::cout << PeakIndexInMountainArray(arr1) << std::endl;
//
//	// Example 2
//	std::vector<int> arr2 = { 0, 2, 1, 0 };
//	std::cout << PeakIndexInMountainArray(arr2) << std::endl;
//
//	// Example 3
//	std::vector<int> arr3 = { 0, 10, 5, 0 };
//	std::cout << PeakIndexInMountainArray(arr3) << std::endl;
//
//	// Example 4
//	std::vector<int> arr4 = { 0, 10, 7, 5, 2 };
//	std::cout << PeakIndexInMountainArray(arr4) << std::endl;
//}