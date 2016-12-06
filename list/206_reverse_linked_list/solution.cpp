/*
206. Reverse a singly linked list.
https://leetcode.com/problems/reverse-linked-list/

A linked list can be reversed either iteratively or recursively. 
Could you implement both?
*/


/**
 * Definition for singly-linked list.
 */
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:

	// recursively
    ListNode* reverseList(ListNode* head) {
        if (NULL == head || NULL == head->next) {
        	return head;
        }

        ListNode* subListHead = head->next;
        head->next = NULL;
        ListNode* reversedListHead = reverseList(subListHead);
        subListHead->next = head;

        return reversedListHead;
    } 

    // iteratively // need
    ListNode* reverseList(ListNode* head) {
    	if (NULL == head || NULL == head->next) {
    		return head;
    	}

    	ListNode *reversedListHead = NULL;
    	ListNode *nextNode = NULL;

    	while (head != NULL) {
    		nextNode = head->next;
    		head->next = reversedListHead;
    		reversedListHead = head;
    		head = nextNode;
    	}

    	return reversedListHead;
    }

    /* 
    iteratively, define a new pointer:
    newHead -> null, Iterate the original list, each time
    insert the node to the start of the new linked list:

    1. newhead->1->null
    2. newhead->2->null
    ...
    5. newhead->5->4->3->2->null

    return newhead->next.
    */

    ListNode* reverseList(ListNode* head) {
        
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* head = new ListNode(0);

        while (head) {
            ListNode *tmp = newhead->next;
            newhead->next = head;
            head = head->next;
            newhead->next->next = tmp;
        }

        return newhead->next;
    }

};