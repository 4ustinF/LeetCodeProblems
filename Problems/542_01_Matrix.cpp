//#include <iostream>
//#include <vector>
//#include <queue>
//
//// Question
///*
//	542. 01 Matrix - August 17th, 2023
//	Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
//
//	The distance between two adjacent cells is 1.
//*/
//
//// Examples
///*
//	Example 1:
//	Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
//	Output: [[0,0,0],[0,1,0],[0,0,0]]
//
//	Example 2:
//	Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
//	Output: [[0,0,0],[0,1,0],[1,2,1]]
//*/
//
//// Constraints
///*
//	m == mat.length
//	n == mat[i].length
//	1 <= m, n <= 10^4
//	1 <= m * n <= 10^4
//	mat[i][j] is either 0 or 1.
//	There is at least one 0 in mat.
//*/
//
//namespace Question_542
//{
//	std::vector<std::vector<int>> UpdateMatrix(std::vector<std::vector<int>>& mat)
//	{
//		// Populate queue
//		std::queue<std::pair<int, int>> queue;
//		for (int x = 0; x < mat.size(); ++x) 
//		{
//			for (int y = 0; y < mat[0].size(); ++y) 
//			{
//				if (mat[x][y] == 0)
//				{
//					queue.push({ x, y });
//				}
//				else
//				{
//					mat[x][y] = -1;
//				}
//			}
//		}
//
//		int length = 0;
//		const std::vector<std::pair<int, int>> dir = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
//
//		const int height = static_cast<int>(mat.size());
//		const int width =  static_cast<int>(mat[0].size());
//
//		while (!queue.empty()) 
//		{
//			int size = static_cast<int>(queue.size());
//			length++;
//
//			while (size-- > 0) 
//			{
//				const std::pair<int, int> f = queue.front();
//				queue.pop();
//				const int startRow = f.first;
//				const int startCol = f.second;
//
//				// Search all directions,
//				for (int i = 0; i < 4; i++) 
//				{
//					const int row = startRow + dir[i].first;
//					const int col = startCol + dir[i].second;
//
//					if (row < 0 || col < 0 || row == height || col == width || mat[row][col] != -1)
//					{
//						continue;
//					}
//
//					mat[row][col] = length;
//					queue.push({ row, col });
//				}
//			}
//		}
//		return mat;
//	}
//
//	void QuickPrint(const std::vector<std::vector<int>>& mat)
//	{
//		for (const auto& m : mat)
//		{
//			std::cout << "[ ";
//			for (const auto& n : m)
//			{
//				std::cout << n << " ";
//			}
//			std::cout << "]" << std::endl;
//		}
//		std::cout << std::endl;
//	}
//}
//
//using namespace Question_542;
//// Test the code using the examples
//int main()
//{
//	// Example 1 = [[0,0,0],[0,1,0],[0,0,0]]
//	std::vector<std::vector<int>> mat1 = { {0, 0, 0 }, { 0, 1, 0 }, { 0, 0, 0 } };
//	QuickPrint(UpdateMatrix(mat1));
//
//	// Example 2 = [[0,0,0],[0,1,0],[1,2,1]]
//	std::vector<std::vector<int>> mat2 = { {0, 0, 0}, { 0, 1, 0 }, { 1, 1, 1 } };
//	QuickPrint(UpdateMatrix(mat2));
//}