#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;
		ListNode *p = head, *q = head->next;
		while (q != NULL && q->next != NULL)
		{
			p = p->next;
			q = q->next->next;
		}
		ListNode* right = sortList(p->next);
		p->next = NULL;
		ListNode* left = sortList(head);
		return sortListCore(left, right);
	}
	ListNode* sortListCore(ListNode* left, ListNode* right)
	{
		ListNode dummy(0);
		ListNode* p = &dummy;
		while (left != NULL && right != NULL)
		{
			if (left->val < right->val)
			{
				p->next = left;
				left = left->next;
			}
			else
			{
				p->next = right;
				right = right->next;
			}
			p = p->next;
		}
		if (left != NULL) p->next = left;
		if (right != NULL) p->next = right;
		return dummy.next;
	}
};

