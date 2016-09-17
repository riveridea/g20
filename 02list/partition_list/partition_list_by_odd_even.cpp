/*
Given a linked list with even and odd numbers. Give an algorithm for 
making changes to list in such a way that all even numbers apperar 
at the beginning.
*/

/* CPP */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    // Leetcode result: passed, but not fast enough!
    ListNode* partition(ListNode* head) 
    {
        ListNode* beforeStart = NULL;
        ListNode* beforeEnd = NULL;
        ListNode* afterStart = NULL;
        ListNode* afterEnd = NULL;
        
        ListNode* node = head;
        
        while (node != NULL)
        {
            ListNode* tmp = node->next;
            node->next = NULL;
            
            //put even numbers at the beginning of the list
            if ((node->val % 2) == 0  )
            {
                if (beforeStart == NULL)
                {
                    beforeStart = node;
                    beforeEnd = beforeStart;
                }
                else
                {
                    beforeEnd->next = node;
                    beforeEnd = node;
                }
            }
            else
            {
                if (afterStart == NULL)
                {
                    afterStart = node;
                    afterEnd = afterStart;
                }
                else
                {
                    afterEnd->next = node;
                    afterEnd = node;
                }
            }
            
            node = tmp;
        }
        
        if (beforeStart == NULL)
        {
            return afterStart;
        }
        
        beforeEnd->next = afterStart;
        return beforeStart;
    }
};