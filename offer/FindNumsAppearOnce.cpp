#include<string>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
using namespace std;
bool IsBit1(int data, int index)
{
	return (data >> index) & 1;
}
void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
	if (data.size() < 2) return;
	int result = data[0];
	for (int i = 1; i < data.size(); i++)
		result ^= data[i];
	if (result == 0) return;
	int count = 0;
	while ((result & 1) == 0)
	{
		result = result >> 1;
		count++;
	}
	*num1 = *num2 = 0;
	for (int i = 0; i < data.size(); i++)
	{
		if (IsBit1(data[i], count))
			*num1 ^= data[i];
		else
			*num2 ^= data[i];
	}
}