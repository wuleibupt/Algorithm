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
void serializeCore(TreeNode* root, ostringstream& stream)
{
	if (root == NULL)
	{
		stream << "# ";
		return;
	}
	stream << root->val << " ";
	serializeCore(root->left, stream);
	serializeCore(root->right, stream);
}
string serialize(TreeNode* root) {
	ostringstream out;
	serializeCore(root, out);
	return out.str();
}
TreeNode* deserializeCore(istringstream& stream)
{
	string val;
	stream >> val;
	if (val == "#") return NULL;
	TreeNode *root = new TreeNode(stoi(val));
	root->left = deserializeCore(stream);
	root->right = deserializeCore(stream);
	return root;
}
TreeNode* deserialize(string data) {
	istringstream in(data);
	return deserializeCore(in);
}