/*
24. Swap Nodes in Pairs
https://leetcode.com/problems/swap-nodes-in-pairs/

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values 
in the list, only nodes itself can be changed.
*/

/* CPP */
// accepted in leetcode
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
    // recursive calls, leetcode result: passed
    ListNode* swapPairs(ListNode* head) {

        if (NULL == head || NULL == head->next) {
            return head;
        }
        
        ListNode* second = head->next;
        head->next = second->next;
        second->next = head;
        head = second;
        head->next->next = swapPairs(head->next->next);
        return head;       
    }

    // iterative calls
};

/*
Problem-32 Reverse the linked list in pairs. If you have a linked list that holds 
1->2->3->4->x, then after the function has been called, the linked list would hold
2->1->4->3->x.

Time Complexity O(n)
Space Complexity O(1)

same as swap nodes in pairs
*/

#include <cstddef>

/* Definition for singly-linked list */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{

public:
    ListNode* ReversePairRecursive(ListNode* head) {
        ListNode* temp;

        if (head == NULL || head->next == NULL) {
            return head;
        } else {
            temp = head->next;
            head->next = ReversePairRecursive(temp->next);
            temp->next = head;
            return temp;
        }

    }

    ListNode* ReversePairIterative(ListNode* head) {
        ListNode* current, temp, temp2;

        ListNode* newHead = head->next;
        ListNode* current = head;

        while (current != NULL && current->next != NULL) {
            temp = current->next;
            temp2 = temp->next;
            temp->next = current;
            current->next = temp2;

            if (current != NULL) {
                current = current->next;
            }
        }

        return newHead;
    }

};