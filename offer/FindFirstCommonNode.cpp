#include<string>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
using namespace std;
struct ListNode
{
	int val;
	ListNode* next;
};
int findListLength(ListNode* pHead1)
{
	ListNode* pnode = pHead1;
	int count = 0;
	while (pnode)
	{
		pnode = pnode->next;
		++count;
	}
	return count;
}
ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
	int len1 = findListLength(pHead1);
	int len2 = findListLength(pHead2);
	ListNode* LongHead = pHead1;
	ListNode* ShortHead = pHead2;
	int len = len1 - len2;
	if (len1 < len2)
	{
		LongHead = pHead2;
		ShortHead = pHead1;
		len = -len;
	}
	ListNode* pNode = LongHead;
	for (int i = 0; i < len; i++)
		pNode = pNode->next;
	ListNode* pNode1 = ShortHead;
	while (pNode != NULL && pNode1 != NULL && pNode != pNode1)
	{
		pNode = pNode->next;
		pNode1 = pNode1->next;
	}
	if (pNode != NULL) return pNode;
	return NULL;
}