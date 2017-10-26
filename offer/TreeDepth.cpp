#include<string>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
};
int TreeDepth(TreeNode* pRoot)
{
	if (pRoot == NULL) return 0;
	return max(TreeDepth(pRoot->left) + 1, TreeDepth(pRoot->right) + 1);
}
