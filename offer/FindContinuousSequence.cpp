#include<string>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
using namespace std;
vector<vector<int> > FindContinuousSequence(int sum) {
	int mid = (1 + sum) >> 1;
	int small = 1;
	int big = 2;
	int currsum = small + big;
	vector<vector<int>> result;
	while (small < mid)
	{
		if (currsum == sum)
		{
			vector<int> vec;
			for (int i = small; i <= big; i++)
				vec.push_back(i);
			result.push_back(vec);
			big++;
			currsum += big;
		}
		else if (currsum > sum)
		{
			currsum -= small;
			small++;
		}
		else
		{
			big++;
			currsum += big;
		}
	}
	return result;
}