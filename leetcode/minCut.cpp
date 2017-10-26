#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
	int minCut(string s) {
		if (s.empty()) return -1;
		int res = 0;
		int len = s.size();
		vector<vector<bool>> matrix(len, move(vector<bool>(len, false)));
		vector<int> cuts(len + 1);
		for (int i = 0; i < len; i++)
			cuts[i] = len - i;
		for (int i = len - 1; i >= 0; --i)
		{
			for (int j = i; j < len; j++)
			{
				if (s[i] == s[j] && (j - i < 2 || matrix[i + 1][j - 1]))
				{
					matrix[i][j] = true;
					cuts[i] = min(cuts[i], cuts[j + 1] + 1);
				}
			}
		}
		res = cuts[0];
		return res - 1;
	}
};


