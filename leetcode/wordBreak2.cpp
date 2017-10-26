#include<string>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		vector<string> res;
		vector<bool> possible(s.size() + 1, true);
		string out = "";
		wordBreakDFS(s, wordDict, 0, possible, out, res);
		return res;
	}
	void wordBreakDFS(string& s, vector<string>& wordDict, int start, vector<bool>& possible, string& out, vector<string>& res)
	{
		if (start == s.size())
		{
			res.push_back(out.substr(0, out.size() - 1));
			return;
		}

		for (int i = start; i < s.size(); i++)
		{
			string word = s.substr(start, i - start + 1);
			if (find(wordDict.begin(), wordDict.end(), word) != wordDict.end() && possible[i + 1] == true)
			{
				out.append(word).append(" ");
				int old = res.size();
				wordBreakDFS(s, wordDict, i + 1, possible, out, res);
				if (res.size() == old) possible[i + 1] = false;
				out.resize(out.size() - word.size() - 1);
			}
		}
	}
};


