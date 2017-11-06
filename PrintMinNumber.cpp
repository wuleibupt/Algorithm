#include<string>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
using namespace std;
static bool cmp(int a, int b)
{
	string AB = to_string(a) + to_string(b);
	string BA = to_string(b) + to_string(a);
	return AB < BA;
}
string PrintMinNumber(vector<int> numbers) {
	if (numbers.empty()) return "";
	string ans = "";
	sort(numbers.begin(), numbers.end(), cmp);
	for (int i = 0; i < numbers.size(); i++)
		ans += to_string(numbers[i]);
	return ans;
}





