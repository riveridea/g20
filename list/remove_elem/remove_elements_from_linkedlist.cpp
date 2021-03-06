/*
Remove Linked List Elements:
https://leetcode.com/problems/remove-linked-list-elements/

Remove all elements from a linked list of integers that
have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
*/

/**
 * Definition for singly-linked list.
 * 
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) {
            return NULL;
        }
        
        // create a dummy headnode, in case
        // we need to delete the first node.
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        head = dummy;
        
        // if delete, then always keep the
        // previous node.
        while (dummy->next) {
            if (dummy->next->val == val) {
                dummy->next = dummy->next->next;
            } else {
                dummy = dummy->next;
            }
        }
        
        return head->next;
    }
};