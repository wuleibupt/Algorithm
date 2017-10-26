#include<string>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
#include<queue>
#include<sstream>
using namespace std;
class Solution {
public:
	void push(int value) {
		stack1.push(value);
		if (stack2.empty() || stack2.top() > value)
			stack2.push(value);
		else
			stack2.push(stack2.top());
	}
	void pop() {
		stack1.pop();
		stack2.pop();
	}
	int top() {
		return stack1.top();
	}
	int min() {
		return stack2.top();
	}
	stack<int> stack1;
	stack<int> stack2;
};