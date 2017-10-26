#include<string>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
struct TreeLinkNode
{
	int val;
	TreeLinkNode* left;
	TreeLinkNode* right;
	TreeLinkNode* next;
};
TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
	if (pNode == NULL) return NULL;
	if (pNode->right != NULL)
	{
		pNode = pNode->right;
		while (pNode->left != NULL) pNode = pNode->left;
		return pNode;
	}
	while (pNode->next != NULL)
	{
		if (pNode->next->left == pNode) return pNode->next;
		pNode = pNode->next;
	}
	return NULL;
}