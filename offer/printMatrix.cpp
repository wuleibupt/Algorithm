#include<iostream>
#include<vector>
using namespace std;
vector<int> printMatrix(vector<vector<int> > matrix) {
	vector<int> res;
	int row = matrix.size();
	int col = matrix[0].size();
	int circle = ((row < col ? row : col) - 1) / 2 + 1;
	for (int i = 0; i < circle; i++)
	{
		for (int j = i; j < col - i; j++)
			res.push_back(matrix[i][j]);
		for (int j = i + 1; j < row - i; j++)
			res.push_back(matrix[j][col - i - 1]);
		for (int j = col - i - 2; j >= i && (row - i - 1 != i); j--)
			res.push_back(matrix[row - 1 - i][j]);
		for (int j = row - i - 2; j > i && (col - i - 1 != i); j--)
			res.push_back(matrix[j][i]);
	}
	return res;
}

