//#include <iostream>
//#include <vector>
//
//// Question
///*
//	1489. Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree - August 19th, 2023
//	Given a weighted undirected connected graph with n vertices numbered from 0 to n - 1, and an array edges where edges{i} = {ai, bi, weighti} represents a bidirectional and weighted edge between nodes ai and bi. A minimum spanning tree (MST) is a subset of the graph's edges that connects all vertices without cycles and with the minimum possible total edge weight.
//
//	Find all the critical and pseudo-critical edges in the given graph's minimum spanning tree (MST). An MST edge whose deletion from the graph would cause the MST weight to increase is called a critical edge. On the other hand, a pseudo-critical edge is that which can appear in some MSTs but not all.
//
//	Note that you can return the indices of the edges in any order.
//*/
//
//// Examples
///*
//	Example 1:
//	Input: n = 5, edges = {{0,1,1},{1,2,1},{2,3,2},{0,3,2},{0,4,3},{3,4,3},{1,4,6}}
//	Output: {{0,1},{2,3,4,5}}
//
//	Example 2:
//	Input: n = 4, edges = {{0,1,1},{1,2,1},{2,3,1},{0,3,1}}
//	Output: {{},{0,1,2,3}}
//	Explanation: We can observe that since all 4 edges have equal weight, choosing any 3 edges from the given 4 will yield an MST. Therefore all 4 edges are pseudo-critical.
//*/
//
//// Constraints
///*
//	2 <= n <= 100
//	1 <= edges.length <= min(200, n * (n - 1) / 2)
//	edges{i}.length == 3
//	0 <= ai < bi < n
//	1 <= weighti <= 1000
//	All pairs (ai, bi) are distinct.
//*/
//
//namespace Question_1489
//{
//	std::vector<std::vector<int>> FindCriticalAndPseudoCriticalEdges(int n, std::vector<std::vector<int>>& edges)
//	{
//		//std::vector<std::vector<int>> Output;
//		return {};
//
//
//	}
//
//	void QuickPrint(const std::vector<std::vector<int>>& edges)
//	{
//		for (const auto& edge : edges)
//		{
//			std::cout << "[ ";
//			for (int num : edge)
//			{
//				std::cout << num << " ";
//			}
//			std::cout << "]" << " ";
//		}
//		std::cout << std::endl;
//	}
//}
//
//using namespace Question_1489;
//// Test the code using the examples
//int main()
//{
//	// Example 1
//	std::vector<std::vector<int>> edges1 = { {0, 1, 1} ,{1, 2, 1}, {2, 3, 2}, {0, 3, 2}, {0, 4, 3}, {3, 4, 3}, {1, 4, 6} };
//	QuickPrint(FindCriticalAndPseudoCriticalEdges(5, edges1));
//
//	//std::vector<std::vector<int>> edges2 = { {0, 1, 1}, {1, 2, 1}, {2, 3, 1}, {0, 3, 1} };
//	//QuickPrint(FindCriticalAndPseudoCriticalEdges(4, edges2));
//
//}