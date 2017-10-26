#include<string>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
class Solution
{
public:
	//Insert one char from stringstream
	void Insert(char ch)
	{
		s += ch;
		hash[ch]++;
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{

		for (int i = 0; i < s.size(); i++)
			if (hash[s[i]] == 1)
				return s[i];
		return '#';
	}
	string s;
	char hash[256] = { 0 };
};
