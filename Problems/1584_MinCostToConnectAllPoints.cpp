//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//// Question
///*
//	1584. Min Cost to Connect All Points - August 19th, 2023
//	You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].
//
//	The cost of connecting two points {xi, yi} and {xj, yj} is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.
//	
//	Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.
//*/
//
//// Examples
///*
//	Example 1:
//	Input: points = {{0,0},{2,2},{3,10},{5,2},{7,0}}
//	Output: 20
//	
//	Example 2:
//	Input: points = {{3,12},{-2,5},{-4,1}}
//	Output: 18
//*/
//
//// Constraints
///*
//	1 <= points.length <= 1000
//	-10^6 <= xi, yi <= 10^6
//	All pairs (xi, yi) are distinct.
//*/
//
//namespace Question_1584
//{
//	// Kruscals Algorithm
//	// Sort all edges by weight
//	// Add edge if it does not create a cycle
//	// Continue until you added n-1 edges
//	int MinCostConnectPoints(std::vector<std::vector<int>>& points) 
//	{
//		std::vector<std::vector<int>> edgelist; // Each list will consist of weight, fromIndex, toIndex
//
//		const int pointsSize = static_cast<int>(points.size());
//		for (int i = 0; i < pointsSize; ++i)
//		{
//			for (int j = i + 1; j < pointsSize; ++j)
//			{
//				const int weight = std::abs(points[i][0] - points[j][0]) + std::abs(points[i][1] - points[j][1]);
//				edgelist.push_back({ weight, i, j});
//			}
//		}
//
//		// Sort the edge list by weights
//		std::sort(edgelist.begin(), edgelist.end());
//
//		return 0;
//	}
//}
//
//using namespace Question_1584;
//// Test the code using the examples
//int main()
//{
//	// Example 1 = 20
//	std::vector<std::vector<int>> points1 = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
//	std::cout << MinCostConnectPoints(points1) << std::endl;
//	//MinCostConnectPoints(points1);
//
//	//// Example 2 = 18
//	//std::vector<std::vector<int>> points2 = {{3, 12}, {-2, 5}, {-4, 1}};
//	//std::cout << MinCostConnectPoints(points2) << std::endl;
//}