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
vector<vector<int>> pathAll;
vector<int> path;
vector<vector<int>> FindPath(TreeNode* root, int expectNumber)
{
	if (root == NULL) return pathAll;
	path.push_back(root->val);
	expectNumber -= root->val;
	if (expectNumber == 0 && root->left == NULL && root->right == NULL)
		pathAll.push_back(path);
	FindPath(root->left, expectNumber);
	FindPath(root->right, expectNumber);
	path.pop_back();
	return pathAll;
}