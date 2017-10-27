#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;
int longestConsecutive(vector<int> num)
{
	if (num.empty()) return 0;
	unordered_set<int> set(num.begin(), num.end());
	int res = 1;
	for (int n : num)
	{
		if (set.erase(n))
		{
			int val = n;
			int sum = 1;
			int val_small = val - 1;
			int val_big = val + 1;
			while (set.erase(val_small))
			{
				sum++;
				val_small--;
			}
			while (set.erase(val_big))
			{
				sum++;
				val_big++;
			}
			res = max(sum, res);
		}
	}
	return res;
}