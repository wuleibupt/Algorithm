#include<string>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
#include<queue>
#include<sstream>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};
bool isSubTree(TreeNode* pRootA, TreeNode* pRootB)
{
	if (pRootB == NULL) return true;
	if (pRootA == NULL) return false;
	if (pRootA->val == pRootB->val)
		return isSubTree(pRootA->left, pRootB->left) && isSubTree(pRootA->right, pRootB->right);
	else
		return false;
}
bool hasSubtree(TreeNode* pRootA, TreeNode* pRootB)
{
	if (pRootA == NULL || pRootB == NULL) return false;
	return isSubTree(pRootA, pRootB) || hasSubtree(pRootA->left, pRootB) || hasSubtree(pRootA->right, pRootB);
}
