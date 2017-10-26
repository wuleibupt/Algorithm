#include<string>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
using namespace std;
long long mergeSort(vector<int> &data, vector<int> &copy, int start, int end)
{
	if (start == end)
	{
		copy[start] = data[start];
		return 0;
	}
	int mid = (start + end) >> 1;
	long long left = mergeSort(copy, data, start, mid);
	long long right = mergeSort(copy, data, mid + 1, end);
	int i = mid;
	int j = end;
	int indexcopy = end;
	long long count = 0;
	while (i >= start&&j >= mid + 1)
	{
		if (data[i]>data[j])
		{
			copy[indexcopy--] = data[i--];
			count = count + j - mid;
		}
		else
		{
			copy[indexcopy--] = data[j--];
		}
	}
	for (; i >= start; i--)
		copy[indexcopy--] = data[i];
	for (; j >= mid + 1; j--)
		copy[indexcopy--] = data[j];
	return left + right + count;
}
int InversePairs(vector<int> data) {
	if (data.empty()) return 0;
	vector<int> copy(data);
	long long ans = mergeSort(data, copy, 0, data.size() - 1);
	return ans % 1000000007;
}








