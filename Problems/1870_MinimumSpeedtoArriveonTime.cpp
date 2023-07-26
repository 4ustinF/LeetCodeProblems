#include <iostream>
#include <vector>

// Question
/*
	1870. Minimum Speed to Arrive on Time - July 26th, 2023
	You are given a floating-point number hour, representing the amount of time you have to reach the office. To commute to the office, you must take n trains in sequential order. You are also given an integer array dist of length n, where dist[i] describes the distance (in kilometers) of the ith train ride.

	Each train can only depart at an integer hour, so you may need to wait in between each train ride.
	
	For example, if the 1st train ride takes 1.5 hours, you must wait for an additional 0.5 hours before you can depart on the 2nd train ride at the 2 hour mark.
	Return the minimum positive integer speed (in kilometers per hour) that all the trains must travel at for you to reach the office on time, or -1 if it is impossible to be on time.
	
	Tests are generated such that the answer will not exceed 107 and hour will have at most two digits after the decimal point.
*/

// Examples
/*
	Example 1:
	Input: dist = [1,3,2], hour = 6
	Output: 1
	Explanation: At speed 1:
	- The first train ride takes 1/1 = 1 hour.
	- Since we are already at an integer hour, we depart immediately at the 1 hour mark. The second train takes 3/1 = 3 hours.
	- Since we are already at an integer hour, we depart immediately at the 4 hour mark. The third train takes 2/1 = 2 hours.
	- You will arrive at exactly the 6 hour mark.

	Example 2:
	Input: dist = [1,3,2], hour = 2.7
	Output: 3
	Explanation: At speed 3:
	- The first train ride takes 1/3 = 0.33333 hours.
	- Since we are not at an integer hour, we wait until the 1 hour mark to depart. The second train ride takes 3/3 = 1 hour.
	- Since we are already at an integer hour, we depart immediately at the 2 hour mark. The third train takes 2/3 = 0.66667 hours.
	- You will arrive at the 2.66667 hour mark.

	Example 3:
	Input: dist = [1,3,2], hour = 1.9
	Output: -1
	Explanation: It is impossible because the earliest the third train can depart is at the 2 hour mark.
*/

// Constraints
/*
	n == dist.length
	1 <= n <= 105
	1 <= dist[i] <= 105
	1 <= hour <= 109
	There will be at most two digits after the decimal point in hour.
*/

namespace Question_1870
{
	double GetTimeOnSpeed(std::vector<int>& dist, int speed)
	{
		double totalTime = 0.0;
		const int lastIndex = static_cast<int>(dist.size()) - 1;

		for (int i = 0; i < lastIndex; ++i)
		{
			// Due to having to the wait for the next train we have to round up
			totalTime += ceil(static_cast<double>(dist[i]) / static_cast<double>(speed));
		}

		// Since this is the last train we dont need to round up to wait
		totalTime += static_cast<double>(dist[lastIndex]) / static_cast<double>(speed);

		return totalTime;
	}

	int MinSpeedOnTime(std::vector<int>& dist, double hour)
	{
		int lowerRange = 1;
		int upperRange = 10000000; // 1e7
		int minSpeed = -1;

		while (lowerRange <= upperRange) {
			const int midRange = (lowerRange + upperRange) / 2;

			// Move to the lower half.
			if (GetTimeOnSpeed(dist, midRange) <= hour) {
				minSpeed = midRange;
				upperRange = midRange - 1;
			}
			else {
				// Move to the upper half.
				lowerRange = midRange + 1;
			}
		}
		return minSpeed;
	}
}

//using namespace Question_1870;
//// Test the code using the examples
//int main()
//{
//	// Example 1 = 1
//	std::vector<int> distances1 = {1, 3, 2};
//	std::cout << "Minimum time: " << MinSpeedOnTime(distances1, 6.0) << std::endl;
//
//	// Example 2 = 3
//	std::vector<int> distances2 = { 1, 3, 2 };
//	std::cout << "Minimum time: " << MinSpeedOnTime(distances2, 2.7) << std::endl;
//
//	// Example 3 = -1
//	std::vector<int> distances3 = { 1, 3, 2 };
//	std::cout << "Minimum time: " << MinSpeedOnTime(distances3, 1.9) << std::endl;
//
//	// Example 4 = 4
//	std::vector<int> distances4 = { 1, 3, 2, 10 };
//	std::cout << "Minimum time: " << MinSpeedOnTime(distances4, 6.0) << std::endl;
//
//	// Example 5 = 2
//	std::vector<int> distances5 = { 1, 2, 2, 2, 1, 2 };
//	std::cout << "Minimum time: " << MinSpeedOnTime(distances5, 8.0) << std::endl;
//}