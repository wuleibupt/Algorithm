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
bool isSymmetricalCore(TreeNode* left, TreeNode* right)
{
	if (left == NULL) return (right == NULL);
	if (right == NULL) return false;
	if (left->val != right->val) return false;
	return isSymmetricalCore(left->right, right->left) && isSymmetricalCore(left->left, right->right);
}
bool isSymmetrical(TreeNode* pRoot)
{
	if (pRoot == NULL)
		return true;
	return isSymmetricalCore(pRoot->left, pRoot->right);
}