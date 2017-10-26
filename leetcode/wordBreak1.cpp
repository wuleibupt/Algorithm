#include<string>
#include<iostream>
#include<vector>
bool wordBreak(string s, unordered_set<string> &dict) {
	int len = s.size();
	vector<bool> dp(len + 1, false);
	dp[0] = true;
	for (int pos = 0; pos < len; pos++)
	{
		for (int i = pos; dp[pos] && i < len; ++i)
		{
			if (dict.find(s.substr(pos, i - pos + 1)) != dict.end())
				dp[i + 1] = true;
		}
	}
	return dp[len];
}
