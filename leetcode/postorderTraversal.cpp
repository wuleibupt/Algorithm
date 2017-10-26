#include<string>
#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;	
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> vec;
		postorderTraversal(root, vec);
		return vec;
	}
	void postorderTraversal(TreeNode* root, vector<int>& vec)
	{
		if (root != NULL)
		{
			postorderTraversal(root->left, vec);
			postorderTraversal(root->right, vec);
			vec.push_back(root->val);
		}
	}
};

