#include<string>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL){}
};
ListNode* deleteDuplication(ListNode* pHead)
{
	ListNode* dummy = new ListNode(0);
	dummy->next = pHead;
	ListNode* pnode = pHead;
	ListNode* last = dummy;
	while (pnode != NULL && pnode->next != NULL)
	{
		if (pnode->val == pnode->next->val)
		{
			int val = pnode->val;
			while (pnode != NULL && pnode->val == val)
				pnode = pnode->next;
			last->next = pnode;
		}
		else
		{
			last = pnode;
			pnode = pnode->next;
		}
	}
	return dummy->next;
}