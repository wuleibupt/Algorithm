#include<string>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
using namespace std;
bool IsPopOrder(vector<int> pushV, vector<int> popV) {
	stack<int> stack1;
	int j = 0;
	for (int i = 0; i<pushV.size(); i++)
	{
		stack1.push(pushV[i]);
		while (!stack1.empty() && stack1.top() == popV[j])
		{
			stack1.pop();
			j++;
		}
	}
	return stack1.empty();
}

