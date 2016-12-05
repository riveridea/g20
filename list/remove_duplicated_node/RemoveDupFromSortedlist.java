/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
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
// passed in Leetcode

public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if(head == null || head.next == null)   return head;
         
        ListNode node = head;
        // better to ListNode temp = new ListNode(x) here
        while(node != null) {
            ListNode tmp = node.next; // tmp = node.next
            while(tmp != null && node.val == tmp.val) {
                tmp = tmp.next;
            }
            node.next = tmp;
            node = node.next; // node = tmp; is also OK
        }
         
        return head;
    }
}

/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/


/* Java */

// passed by leetcode

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
    public ListNode deleteDuplicates(ListNode head) {
        ListNode prev = new ListNode(0);
        prev.next = head;
        head = prev;
        
        ListNode n1 = head;
        
        while (n1.next != null) {
            ListNode n2 = n1.next;
            
            while (n2.next != null && n2.next.val == n2.val) {
                n2 = n2.next;
            }
            

            // this part attention
            if (n2 != n1.next) {
                n1.next = n2.next;
            } else {
                n1 = n1.next;
            }
        }
        
        return head.next;
    }
}