/*
Problem 36: Split a circular linked list into two equal parts.
If the number of nodes in the list one odd then make first list
one node extra than second list.
*/

struct ListNode  {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution  {
Time: O(n), Space: O(1)

public:
	void SplitList(ListNode *head, ListNode **head1, ListNode **head2) {
		ListNode *slowPtr = head;
		ListNode *fastPtr = head;

		if (head == NULL) {
			return;
		}

		// If there are odd nodes in th circular list then fastPtr->next
		// becomes head and for even nodes fastPtr->next->next becomes
		// head.

		while (fastPtr->next != head && fastPtr->next->next != head) {
			fastPtr = fastPtr->next->next;
			slowPtr = slowPtr->next;
		}

		// If thre are even elements in list then move fastPtr
		if (fastPtr->next->next == head) {
			fastPtr = fastPtr->next;
		}

		// set the head pointer of first half
		*head1 = head;

		// set the head pointer of second half
		if (head->next != head) {
			*head2 = slowPtr->next;
		}

		// make second half circular
		fastPtr->next = slowPtr->next;

		// make first half circular
		slowPtr->next = head;

	}

};