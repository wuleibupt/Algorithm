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
};
ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	if (pHead == NULL || pHead->next == NULL)
		return NULL;
	ListNode* fast = pHead;
	ListNode* slow = pHead;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			break;
	}
	fast = pHead;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return fast;
}