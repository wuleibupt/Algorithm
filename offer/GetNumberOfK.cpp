#include<string>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
using namespace std;
int getFirstK(vector<int> data, int k, int start, int end)
{
	int mid = (start + end) >> 1;
	while (start <= end)
	{
		if (data[mid]>k)
		{
			end = mid - 1;
		}
		else if (data[mid] < k)
		{
			start = mid + 1;
		}
		else if (mid - 1 >= 0 && data[mid - 1] == k)
		{
			end = mid - 1;
		}
		else
		{
			return mid;
		}
		mid = (start + end) >> 1;
	}
	return -1;

}
int getLastK(vector<int> data, int k, int start, int end)
{
	int mid = (start + end) >> 1;
	while (start <= end)
	{
		if (data[mid] > k)
		{
			end = mid - 1;
		}
		else if (data[mid] < k)
		{
			start = mid + 1;
		}
		else if (mid + 1 < data.size() && data[mid + 1] == k)
		{
			start = mid + 1;
		}
		else
		{
			return mid;
		}
		mid = (start + end) >> 1;
	}
	return -1;
}
int GetNumberOfK(vector<int> data, int k) {
	if (data.empty()) return 0;
	int firstK = getFirstK(data, k, 0, data.size() - 1);
	int lastK = getLastK(data, k, 0, data.size() - 1);
	if (lastK != -1 && firstK != -1)
		return lastK - firstK + 1;
	return 0;
}