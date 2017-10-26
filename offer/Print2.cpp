#include<string>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};
vector<vector<int> > Print2(TreeNode*pRoot) {
	if (pRoot == NULL) return{};
	vector<vector<int>> result;
	queue<TreeNode*> que;
	que.push(pRoot);
	while (!que.empty())
	{
		int i = 0;
		int size = que.size();
		vector<int> vec;
		while (i++ < size)
		{
			TreeNode* node = que.front();
			que.pop();
			vec.push_back(node->val);
			if (node->left != NULL)
				que.push(node->left);
			if (node->right != NULL)
				que.push(node->right);
		}
		result.push_back(vec);
	}
	return result;
}