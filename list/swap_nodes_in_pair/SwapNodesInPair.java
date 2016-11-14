/*
24. Swap Nodes in Pairs
https://leetcode.com/problems/swap-nodes-in-pairs/

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the 
values in the list, only nodes itself can be changed.
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
    // recursive calls, leetcode result: passed
    ListNode* swapPairs(ListNode* head) {

         if (NULL == head || NULL == head->next)
        {
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






/* Java */

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode swapPairs(ListNode head) {
        
        ListNode helper = new ListNode(0);
        helper.next = head;
        ListNode n1 = helper, n2=head;
        
        while(n2!=null && n2.next!=null){
            // save next processing node
            ListNode temp = n2.next.next;

            //pointer turn around
            n2.next.next=n1.next;

            // first loop, new head to seconde node.
            n1.next=n2.next; 

            // connect to the rest of the list
            n2.next=temp;

            // move forward
            n1=n2;
            n2=n1.next;
        }
        
        return helper.next;
    }
}
