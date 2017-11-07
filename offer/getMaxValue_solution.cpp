#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int getMaxValue_solution(vector<vector<int>> values)
{
	if (values.size() > 0) return 0;
	int n = values.size();
	int m = values[0].size();
	vector<vector<int>> maxValues(n, move(vector<int>(m, 0)));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int left = 0;
			int up = 0;
			if (i>0) up = maxValues[i - 1][j];
			if (j>0) left = maxValues[i][j - 1];
			maxValues[i][j] = max(up, left) + values[i][j];
		}
	}
	int maxValue = maxValues[n - 1][m - 1];
	return maxValue;
}