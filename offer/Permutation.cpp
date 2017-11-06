#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void swap(char& a, char& b)
{
	char temp = a;
	a = b;
	b = temp;
}
void PermutationCore(string str, vector<string>& ans, int k){
	if (k == str.size())
		ans.push_back(str);
	for (int i = k; i<str.size(); i++)
	{
		if (i != k && str[i] == str[k])
			continue;
		swap(str[i], str[k]);
		PermutationCore(str, ans, k + 1);
		//swap(str[i], str[k]);
	}
}
vector<string> Permutation(string str) {
	vector<string> ans;
	if (str == "")return ans;
	sort(begin(str), end(str));
	PermutationCore(str, ans, 0);
	sort(ans.begin(), ans.end());
	/*auto it = unique(begin(ans), end(ans));
	ans.erase(it, ans.end());*/
	return ans;
}
