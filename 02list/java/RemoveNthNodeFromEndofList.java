/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/

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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        
        if (head == null || n < 1) {
            return null;
        }
        
        ListNode first = head;
        ListNode second = head;
        
        for (int i = 1; i < n; i++) {
            if (first.next != null) {
                first = first.next;
            } else {
                return null;
            }
        }
        
        if (first == null) {
            return null;
        }
        
        while (first.next != null) {
            first = first.next;
            second = second.next;
        }
        
        return second;
    }
}