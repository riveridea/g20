/*
https://leetcode.com/problems/remove-duplicates-from-sorted-list

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

// CPP struct constructor
// http://www.dev-hq.net/c++/11--constructors-and-destructors
struct ListNode  {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution  {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        // decide empty list or one node list
        if (head == NULL || head->next == NULL) {
        	return head;
        }

        // set start point
        ListNode *node = head;

        // set the runner pointer, it compares its value
        // with the start-point's
        while (node != NULL) {
        	ListNode *tmp = node->next;

        	while (tmp != NULL && tmp->val == node->val) {
        		tmp = tmp->next;
        	}

            // ignore the nodes with same value
        	node->next = tmp;
            // reset node and repeat
        	node = node->next;
        }

        return head;
    }
};

int main() {

    

    return 0;
}