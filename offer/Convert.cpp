#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
};
TreeNode* leftlast = NULL;
TreeNode* pre = NULL;
TreeNode* Convert(TreeNode* pRootOfTree)
{
	if (pRootOfTree == NULL) return NULL;
	Convert(pRootOfTree->left);
	pRootOfTree->left = pre;
	if (pre != NULL) pre->right = pRootOfTree;
	pre = pRootOfTree;
	leftlast = (leftlast == NULL) ? pRootOfTree : leftlast;
	Convert(pRootOfTree->right);
	return leftlast;
}
