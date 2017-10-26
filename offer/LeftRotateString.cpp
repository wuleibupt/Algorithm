#include<string>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
using namespace std;
string LeftRotateString(string str, int n) {
	if (str == "") return "";
	int len = str.size();
	n = n%len;
	str += str;
	return str.substr(n, len);
}
