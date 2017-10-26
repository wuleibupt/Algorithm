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
vector<int> PrintFromTopToBottom(TreeNode* root) {
	vector<int> vec;
	if (root == NULL) return vec;
	queue<TreeNode*> que;
	que.push(root);
	while (!que.empty())
	{
		TreeNode* node = que.front();
		vec.push_back(node->val);
		que.pop();
		if (node->left != NULL)
			que.push(node->left);
		if (node->right != NULL)
			que.push(node->right);
	}
	return vec;
}