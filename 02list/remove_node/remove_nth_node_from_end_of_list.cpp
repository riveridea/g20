/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/
// not passed

#include <iostream>
#include <string>
using namespace std;

/* Definition for singly-linked list */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}  
};

class Solution 
{

public:
    ListNode* removeNthFromEnd(ListNode *head, int n) {
    	if (NULL == head || 0 == n) {
    		return head;
    	}

    	if (NULL == head->next) {
    		return NULL;
    	}

    	ListNode *first = head;
    	ListNode *second = head;

    	while (n > 0) {
    		first = first->next;
    		n--;
    	}

    	if (NULL == first) {
    		return NULL;
    	}

    	while (first->next != NULL) {
 			first = first->next;
 			second = second->next;
    	}

    	ListNode *target = second;
    	second->next = second->next->next;

    	return second;
    }
};
    