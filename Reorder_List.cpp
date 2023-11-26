/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	void reorderList(ListNode* head) {
		ListNode *slow, *fast;
		slow = fast = head;
		while (fast and fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode *first = head;
		ListNode *second = slow->next;
		slow->next = NULL;

		ListNode *prev = NULL;
		ListNode *curr = second;


		while (curr) {
			ListNode* temp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = temp;
		}
		second = prev;
		while (second) {
			ListNode* temp;
			temp = first->next;
			first->next = second;
			ListNode* temp2;

			temp2 = second->next;

			second->next = temp;
			first = temp;
			second = temp2;

		}
		//	return head;
	}
};