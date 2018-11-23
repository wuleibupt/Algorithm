#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#复制复杂链表
struct RandomListNode
{
	int val;
	RandomListNode* next;
	RandomListNode* random;
	RandomListNode(int x) :val(x), next(NULL), random(NULL){}
};
RandomListNode* Clone(RandomListNode* pHead)
{
	if (pHead == NULL) return NULL;
	RandomListNode* pNode = pHead;
	while (pNode != NULL)
	{
		RandomListNode* node = new RandomListNode(pNode->val);
		node->next = pNode->next;
		pNode->next = node;
		pNode = node->next;
	}
	pNode = pHead;
	while (pNode != NULL)
	{
		RandomListNode* clone = pNode->next;
		if (pNode->random != NULL)
			clone->random = pNode->random->next;
		pNode = clone->next;
	}
	RandomListNode* pClone = pHead->next;
	pNode = pHead;
	RandomListNode* temp;
	while (pNode->next != NULL)
	{
		temp = pNode->next;
		pNode->next = temp->next;
		pNode = temp;
	}
	return pClone;
}
