/*
Given a sorted linked list, delete all duplicates such that each element 
appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

/* CPP */

#include <iostream>
#include <string>
using namespace std;

/* Definition for singly-linked list. */

struct ListNode  {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution  {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if (head == NULL || head->next == NULL) {
        	return head;
        }

        ListNode *node = head;

        while (node != NULL) {
        	ListNode *tmp = node->next;

        	while (tmp != NULL && tmp->val == node->val) {
        		tmp = tmp->next;
        	}

        	node->next = tmp;
        	node = node->next;
        }

        return head;
    }
};