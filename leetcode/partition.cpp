#include<string>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> res;
		vector<string> path;
		dfs(s, path, res);
		return res;
	}
	void dfs(string s, vector<string>&path, vector<vector<string>>& res)
	{
		if (s.length() == 0)
		{
			res.push_back(path);
			return;
		}
		for (int i = 0; i < s.size(); i++)
		{
			int begin = 0;
			int end = i;
			while (begin < end)
			{
				if (s[begin] == s[end])
				{
					begin++;
					end--;
				}
				else
					break;
			}
			if (begin >= end)
			{
				path.push_back(s.substr(0, i + 1));
				dfs(s.substr(i + 1), path, res);
				path.pop_back();
			}
		}
	}
};

