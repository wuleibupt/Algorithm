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
vector<vector<int> > Print1(TreeNode*pRoot) {
	if (pRoot == NULL) return{};
	vector<vector<int>> result;
	int layer = 1;
	stack<TreeNode*> stack1;
	stack<TreeNode*> stack2;
	stack1.push(pRoot);
	while (!stack1.empty() || !stack2.empty())
	{
		if (layer % 2 != 0)
		{
			vector<int> vec;
			while (!stack1.empty())
			{
				TreeNode* pnode = stack1.top();
				vec.push_back(pnode->val);
				stack1.pop();
				if (pnode->left != NULL)
					stack2.push(pnode->left);
				if (pnode->right != NULL)
					stack2.push(pnode->right);
			}
			result.push_back(vec);
			layer++;
		}
		else
		{
			vector<int> vec;
			while (!stack2.empty())
			{
				TreeNode* pnode = stack2.top();
				vec.push_back(pnode->val);
				stack2.pop();
				if (pnode->right != NULL)
					stack1.push(pnode->right);
				if (pnode->left != NULL)
					stack1.push(pnode->left);
			}
			result.push_back(vec);
			layer++;
		}
	}
	return result;
}