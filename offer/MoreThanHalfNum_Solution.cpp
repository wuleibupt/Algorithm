#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int MoreThanHalfNum_Solution(vector<int> numbers)
{
	if (numbers.empty()) return 0;
	int num = numbers[0];
	int times = 1;
	for (int i = 1; i < numbers.size(); i++)
	{
		if (numbers[i] == num) times++;
		else times--;
		if (times == 0)
		{
			num = numbers[i];
			times = 1;
		}
	}
	times = 0;
	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == num) times++;
	}
	if (times * 2>numbers.size()) return num;
	return 0;
}