#include<string>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};
class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (node == NULL) return NULL;
		unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
		UndirectedGraphNode* p = new UndirectedGraphNode(node->label);
		map[node] = p;
		queue<UndirectedGraphNode*> que;
		que.push(node);
		while (que.size())
		{
			UndirectedGraphNode* q = que.front();
			que.pop();
			for (auto v : q->neighbors)
			{
				if (map[v] == NULL)
				{
					UndirectedGraphNode* next = new UndirectedGraphNode(v->label);
					map[v] = next;
					que.push(v);
				}
				map[q]->neighbors.push_back(map[v]);
			}
		}
		return p;
	}
};

