#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool hasPathCore(char* matrix, int rows, int cols, int i, int j, char* str, int k, vector<int>& flag)
{
	int index = i*cols + j;
	if (i < 0 || i >= rows || j < 0 || j >= cols || matrix[index] != str[k] || flag[index] == 1)
	{
		return false;
	}
	if (k == strlen(str) - 1) return true;
	flag[index] = 1;
	if (hasPathCore(matrix, rows, cols, i - 1, j, str, k + 1, flag)
		|| hasPathCore(matrix, rows, cols, i + 1, j, str, k + 1, flag)
		|| hasPathCore(matrix, rows, cols, i, j - 1, str, k + 1, flag)
		|| hasPathCore(matrix, rows, cols, i, j + 1, str, k + 1, flag))
		return true;
	flag[index] = 0;
	return false;
}
bool hasPath(char* matrix, int rows, int cols, char* str)
{
	vector<int> flag(rows*cols, 0);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (hasPathCore(matrix, rows, cols, i, j, str, 0, flag))
				return true;
		}
	}
	return false;
}