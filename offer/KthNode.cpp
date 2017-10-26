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
int times = 0;
TreeNode* KthNode(TreeNode* pRoot, int k)
{
	if (pRoot)
	{
		TreeNode* ret = KthNode(pRoot->left, k);
		if (ret) return ret;
		if (++times == k) return pRoot;
		ret = KthNode(pRoot->right, k);
		if (ret) return ret;
	}
	return NULL;
}