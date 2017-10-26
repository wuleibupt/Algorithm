#include<string>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
#include<queue>
#include<sstream>
using namespace std;
int numSum(int i)
{
	int sum = 0;
	while (i)
	{
		sum += i % 10;
		i /= 10;
	}
	return sum;
}
int movingCountCore(int i, int j, int rows, int cols, vector<int>& flag, int threshold)
{
	int index = i*cols + j;
	if (i < 0 || i >= rows || j<0 || j >= cols || numSum(i) + numSum(j)>threshold || flag[index] == 1)
		return 0;
	flag[index] = 1;
	return movingCountCore(i - 1, j, rows, cols, flag, threshold)
		+ movingCountCore(i + 1, j, rows, cols, flag, threshold)
		+ movingCountCore(i, j - 1, rows, cols, flag, threshold)
		+ movingCountCore(i, j + 1, rows, cols, flag, threshold)
		+ 1;
}
int movingCount(int threshold, int rows, int cols)
{
	vector<int> flag(rows*cols, 0);
	return movingCountCore(0, 0, rows, cols, flag, threshold);
}
