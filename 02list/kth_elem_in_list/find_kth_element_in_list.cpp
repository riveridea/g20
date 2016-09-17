/*
Cracking The Coding Interview 5th, Question 2.2

# Implement an algorithm to find the kth (or nth) to last element 
of a singly linked list.

# Folow Up
Can we improve the complexity? Yes, with hash-table.
Can we not use the hash table? Yes.
Can we solve the problem in one scan? Yes. 
-- Iterative method with two pointers
*/


/**
 * Definition for singly-linked list.
*/

 struct ListNode {
      int val;
      ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
 
// If linked list size is known?

// k = 1, return the last one
// k = 2, return the seconde to last element

class Solution {
public:
// Recursive



// Iterative
// use two ponters, p1 and p2, place them k nodes
// apart in the list by putting p1 at the beginning
// and moving p2 k nodes into the list. Then moving
// them togeter until p2 hit the end of the list
// after Length-k steps. Then p1 will be Length -k
// nodes from the end.	
	ListNode* kthToLast(ListNode *head, int k) {
		if (k <= 0) {
			return head;
		}

		ListNode *p1 = head;
		ListNode *p2 = head;

		// Move p2 forward k nodes into the list.
		for (int i = 0; i < k - 1; i++) {
			if (p2 == NULL) {
				return NULL;
			}

			p2 = p2->next;
		}

		if (p2 == NULL) {
			return NULL;
		}

		// now move p1, p2 at the same speed.
		while (p2->next != NULL) {
			p1 = p1->next;
			p2 = p2->next;
		}

		return p1;
	}

};