#include<iostream>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
};
void Mirror(TreeNode* root)
{
	if (root == NULL) return;
	TreeNode* temp = root->left;
	root->left = root->right;
	root->right = temp;
	Mirror(root->left);
	Mirror(root->right);
}
