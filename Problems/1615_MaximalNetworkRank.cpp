//#include <iostream>
//#include <vector>
//#include <unordered_map>
//#include <unordered_set>
//
//// Question
///*
//	1615. Maximal Network Rank - August 18th, 2023
//	There is an infrastructure of n cities with some number of roads connecting these cities. Each roads[i] = [ai, bi] indicates that there is a bidirectional road between cities ai and bi.
//
//	The network rank of two different cities is defined as the total number of directly connected roads to either city. If a road is directly connected to both cities, it is only counted once.
//
//	The maximal network rank of the infrastructure is the maximum network rank of all pairs of different cities.
//
//	Given the integer n and the array roads, return the maximal network rank of the entire infrastructure.
//*/
//
//// Examples
///*
//	Example 1:
//	0 - 1 - 2
//      \   /
//	    3
//	Input: n = 4, roads = [[0,1],[0,3],[1,2],[1,3]]
//	Output: 4
//	Explanation: The network rank of cities 0 and 1 is 4 as there are 4 roads that are connected to either 0 or 1. The road between 0 and 1 is only counted once.
//
//	Example 2:
//	0 - 1 - 2
//	  \   / |
//		3   4
//	Input: n = 5, roads = [[0,1],[0,3],[1,2],[1,3],[2,3],[2,4]]
//	Output: 5
//	Explanation: There are 5 roads that are connected to cities 1 or 2.
//
//	Example 3:
//	0 - 1 - 2
//	      / |
//		3   4
//
//		5 - 6
//		  \
//            7
//	Input: n = 8, roads = [[0,1],[1,2],[2,3],[2,4],[5,6],[5,7]]
//	Output: 5
//	Explanation: The network rank of 2 and 5 is 5. Notice that all the cities do not have to be connected.
//*/
//
//// Constraints
///*
//	2 <= n <= 100
//	0 <= roads.length <= n * (n - 1) / 2
//	roads[i].length == 2
//	0 <= ai, bi <= n-1
//	ai != bi
//	Each pair of cities has at most one road connecting them.
//*/
//
//namespace Question_1615
//{
//	int MaximalNetworkRank(int n, std::vector<std::vector<int>>& roads)
//	{
//		int maxRank = 0;
//		std::unordered_map<int, std::unordered_set<int>> adj;
//
//		// Construct adjency list 'adj', where adj[node] stores all nodes connected to 'node'.
//		for (auto& road : roads) 
//		{
//			adj[road[0]].insert(road[1]);
//			adj[road[1]].insert(road[0]);
//		}
//
//		// Iterate on each possible pair of nodes.
//		for (int node1 = 0; node1 < n; ++node1) 
//		{
//			for (int node2 = node1 + 1; node2 < n; ++node2) 
//			{
//				// Obtain the rank of the two cities
//				int currentRank = static_cast<int>(adj[node1].size() + adj[node2].size());
//
//				// Subtract by one if they share a common edge. 
//				if (adj[node1].find(node2) != adj[node1].end()) 
//				{
//					--currentRank;
//				}
//
//				// Find the current pair's respective network rank and store if it's maximum till now.
//				maxRank = std::max(maxRank, currentRank);
//			}
//		}
//
//		// Return the maximum network rank.
//		return maxRank;
//	}
//
//}
//
//using namespace Question_1615;
//// Test the code using the examples
//int main()
//{
//	// Example 1 = 4
//	std::vector<std::vector<int>> list1 = { {0, 1}, {0, 3}, {1, 2}, {1, 3} };
//	std::cout << MaximalNetworkRank(4, list1) << std::endl;
//	
//	// Example 2 = 5
//	std::vector<std::vector<int>> list2 = { {0, 1}, {0, 3}, {1, 2}, {1, 3}, {2, 3}, {2, 4} };
//	std::cout << MaximalNetworkRank(5, list2) << std::endl;
//
//	// Example 3 = 5
//	std::vector<std::vector<int>> list3 = { {0, 1}, {1, 2}, {2, 3}, {2, 4}, {5, 6}, {5, 7} };
//	std::cout << MaximalNetworkRank(8, list3) << std::endl;
//}