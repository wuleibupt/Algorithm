#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	int minDepth(TreeNode* root) {
		if (root == NULL) return 0;
		int left = minDepth(root->left);
		int right = minDepth(root->right);
		if (left == 0 || right == 0)
			return 1 + left + right;
		return 1 + min(left, right);
	}
};


