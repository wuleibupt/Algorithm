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
	void reorderList(ListNode* head) {
		if (head == nullptr)
			return;
		ListNode* fast;
		ListNode* slow;
		fast = head->next;
		slow = head;
		while (fast != nullptr && fast->next != nullptr)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		ListNode* pre = slow->next;
		if (pre == nullptr)return;
		ListNode* nex = pre->next;
		while (nex != nullptr)
		{
			pre->next = nex->next;
			nex->next = slow->next;
			slow->next = nex;
			nex = pre->next;
		}
		mergeNode1(head, slow);
	}
	void mergeNode1(ListNode* head1, ListNode* head2)
	{
		ListNode* p = head1;
		ListNode* q = head2->next;
		while (q != nullptr && p != nullptr)
		{
			head2->next = q->next;
			q->next = p->next;
			p->next = q;
			q = head2->next;
			p = p->next->next;
		}
	}
};

