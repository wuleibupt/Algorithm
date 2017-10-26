#include<string>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
string ReverseSentence(string str) {
	string res = "", temp = "";
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			res = " " + temp + res;
			temp = "";
		}
		else
			temp += str[i];
	}
	if (temp.size()>0) res = temp + res;
	return res;
}