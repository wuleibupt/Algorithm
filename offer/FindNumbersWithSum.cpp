#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> FindNumbersWithSum(vector<int> array, int sum) {
	int start = 0;
	int end = array.size() - 1;
	vector<int> result;
	while (start < end)
	{
		if (array[start] + array[end] < sum)
			start++;
		else if (array[start] + array[end] > sum)
			end--;
		else
		{
			result.push_back(array[start]);
			result.push_back(array[end]);
			break;
		}
	}
	return result;
}