#include<string>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
int StrToInt(string str) {
	int n = str.size(), s = 1;
	long long res = 0;
	if (str == "") return res;
	if (str[0] == '-') s = -1;
	for (int i = (str[0] == '-' || str[0] == '+') ? 1 : 0; i < n; ++i)
	{
		if (str[i] < '0' || str[i] > '9') return 0;
		res = res * 10 + str[i] - '0';
	}
	return res*s;
}