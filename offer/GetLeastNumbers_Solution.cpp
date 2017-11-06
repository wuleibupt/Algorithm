#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int patition(vector<int>& data, int start, int end)
{
	int i = start, j = end, key = data[start];
	while (i < j)
	{
		while (i < j && data[j] >= key)j--;
		data[i] = data[j];
		while (i < j&&data[i] <= key)i++;
		data[j] = data[i];
	}
	data[i] = key;
	return i;
}
vector<int> GetLeastNumbers_Solution(vector<int> data, int k)
{
	if (data.empty()) return vector<int>();
	if (k > data.size() || k <= 0) return vector<int>();
	int start = 0;
	int end = data.size() - 1;
	int index = patition(data, start, end);
	while (index != k - 1)
	{
		if (index < k - 1)
		{
			start = index + 1;
			index = patition(data, start, end);
		}
		else
		{
			end = index - 1;
			index = patition(data, start, end);
		}
	}
	vector<int> vec(data.begin(), data.begin() + k);
	return vec;
}