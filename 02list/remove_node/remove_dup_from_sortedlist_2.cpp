/*
https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii

Given a sorted linked list, delete all nodes that have 
duplicate numbers, leaving only distinct numbers from 
the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

/* CPP */

#include <iostream>
#include <string>
using namespace std;

/* Definition for singly-linked list. */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode* head) {

   	// adding a dumb node before the head
        ListNode *pre = new ListNode(0);
        pre->next = head;
        head = pre;

        ListNode *node = head;

        while (node->next != NULL) {
        	ListNode *tmp = node->next;

        	while (tmp->next != NULL && 
        			tmp->next->val == tmp->val) {
        		tmp = tmp->next;
        	}

        	if (tmp == node->next) {
        		node = node->next;
        	} else {
        		node->next = tmp->next;
        	}
        }

        return head->next;  
    }
};