#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int longestSubstringWithoutDeplication(string str)
{
	vector<int> postition(26, -1);
	int curLength = -1;
	int maxLength = INT_MIN;
	for (int i = 0; i < str.size(); i++)
	{
		int pos = postition[str[i] - 'a'];
		if (pos<0 || i - pos>curLength)
			++curLength;
		else
			curLength = i - pos;
		postition[str[i] - 'a'] = i;
		maxLength = max(maxLength, curLength);
	}
	return maxLength;
}