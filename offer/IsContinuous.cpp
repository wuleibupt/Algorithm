#include<string>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
using namespace std;
bool IsContinuous(vector<int> numbers) {
	if (numbers.size() != 5) return false;
	int min = 14;
	int max = -1;
	int flag = 0;
	for (int i = 0; i < numbers.size(); i++)
	{
		int num = numbers[i];
		if (num < 0 || num>13) return false;
		if (num == 0) continue;
		if (((flag >> num) & 1) == 1)return false;
		flag |= (1 << num);
		if (num > max) max = num;
		if (num < min) min = num;
		if (max - min >= 5) return false;
	}
	return true;
}
