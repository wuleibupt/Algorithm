#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
//priority_queue 默认优先级大在对前 greater参数是递增参数，less参数是递减参数
class MedianFinder {
public:
	/** initialize your data structure here. */
	MedianFinder() {
	}
	void addNum(int num) {
		if (p.empty() || num <= p.top()) p.push(num);
		else q.push(num);
		if (p.size() == q.size() + 2)
		{
			q.push(p.top());
			p.pop();
		}
		if (p.size() + 1 == q.size())
		{
			p.push(q.top());
			q.pop();
		}
	}
	double findMedian() {
		return p.size() == q.size() ? (p.top() + q.top()) / 2.0 : p.top();
	}
	priority_queue<int, vector<int>, less<int> > p;
	priority_queue<int, vector<int>, greater<int> > q;
};