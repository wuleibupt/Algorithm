#include<string>
#include<iostream>
#include<vector>
#include<stack>
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
	int sumNumbers(TreeNode* root) {
		int sum = 0;
		if (root == NULL) return sum;
		return sumNumbersCore(root, sum);
	}
	int sumNumbersCore(TreeNode* root, int sum)
	{
		if (root == NULL) return 0;
		sum = sum * 10 + root->val;
		if (root->left == NULL &&root->right == NULL) return sum;
		return sumNumbersCore(root->left, sum) + sumNumbersCore(root->right, sum);
	}
};


