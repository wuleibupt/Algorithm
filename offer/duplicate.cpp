#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool duplicate(vector<int> numbers, int* duplication)
{
	int len = numbers.size();
	for (int i = 0; i < len; i++)
	{
		int index = numbers[i];
		if (index >= len) index -= len;
		if (numbers[index] >= len)
			return index;
		numbers[index] += len;
	}
	return -1;
}
