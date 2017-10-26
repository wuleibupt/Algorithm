#include<string>
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;
		ListNode* Head = new ListNode(0);
		Head->next = insertionSortList(head->next);
		ListNode* p = Head;
		while (p != NULL && p->next != NULL && head->val >= p->next->val)
		{
			p = p->next;
		}
		head->next = p->next;
		p->next = head;
		return Head->next;
	}
};


