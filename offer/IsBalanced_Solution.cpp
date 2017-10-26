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
bool isBalanced = true;
int IsBalancedDepth(TreeNode* pRoot)
{
	if (pRoot == NULL) return 0;
	int left = IsBalancedDepth(pRoot->left);
	int right = IsBalancedDepth(pRoot->right);
	if (abs(left - right) > 1)
		isBalanced = false;
	return right > left ? right + 1 : left + 1;
}
bool IsBalanced_Solution(TreeNode* pRoot) {
	IsBalancedDepth(pRoot);
	return isBalanced;
}