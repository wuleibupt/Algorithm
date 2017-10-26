#include<string>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		if (tokens.empty()) return 0;
		stack<int> stack1;
		for (int i = 0; i < tokens.size(); i++)
		{
			string s = tokens[i];
			if (s == "+" || s == "-" || s == "*" || s == "/")
			{
				int nums2 = stack1.top();
				stack1.pop();
				int nums1 = stack1.top();
				stack1.pop();
				int result = 0;
				if (s == "+")
					result = nums1 + nums2;
				else if (s == "-")
					result = nums1 - nums2;
				else if (s == "*")
					result = nums1*nums2;
				else
					result = nums1 / nums2;
				stack1.push(result);
			}
			else
				stack1.push(stoi(s));
		}
		return stack1.top();
	}
};


