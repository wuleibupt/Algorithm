#include<string>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
using namespace std;
int FindGreatestSumOfSubArray(vector<int> array) {
	if (array.empty()) return 0;
	int currsum = 0;
	int greatestSum = INT_MIN;
	for (int i = 0; i < array.size(); i++)
	{
		if (currsum <= 0)
			currsum = array[i];
		else
			currsum += array[i];
		greatestSum = max(greatestSum, currsum);
	}
	return greatestSum;
}



