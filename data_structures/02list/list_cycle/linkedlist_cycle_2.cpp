/*
Given a linked list, return the node where the cycle begins. 
If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
*/


#include <cstddef>

 /* Definition for singly-linked list. */
 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

    	if (head == NULL || head->next == NULL) {
    		return NULL;
    	}

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL) {
        	if (fast->next == NULL) {
        		return NULL;
        	}

        	slow = slow->next;
        	fast = fast->next->next;
        	
        	if (slow == fast) {
        	    break;
        	}
        }

        if (fast == NULL) {
        	return NULL; // no cycle;
        }

        slow = head;

        while (slow != fast) {
        	slow = slow->next;
        	fast = fast->next;
        }

        // at this point, both slow and fast pointers meet at
        // the enter of the cycle

        return fast;
    }
};