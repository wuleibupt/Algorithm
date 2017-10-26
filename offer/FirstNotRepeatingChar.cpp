#include<string>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
using namespace std;
int FirstNotRepeatingChar(string str) {
	map<char, int> map1;
	for (int i = 0; i < str.size(); i++)
		map1[str[i]]++;
	for (int i = 0; i < str.size(); i++)
		if (map1[str[i]] == 1)
			return i;
	return -1;
}







