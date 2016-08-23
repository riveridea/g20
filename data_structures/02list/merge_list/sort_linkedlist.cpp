/*
Sort a linked list in O(n log n) time using constant space complexity.
*/


/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        
        ListNode slow = head;
        ListNode fast = head.next;
        
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        
        ListNode newHead = slow.next;
        slow.next = null;
        
        head = sortList(head);
        newHead = sortList(newHead);
        
        return mergeLists(head, newHead);
    }
    
    public ListNode mergeLists(ListNode l1, ListNode l2) {
        if (l1 == null) {
            return l2;
        }
        
        if (l2 == null) {
            return l1;
        }
        
        ListNode c1 = (l1.val <= l2.val?l1:l2);
        ListNode c2 = (l1.val <= l2.val?l2:l1);
        
        while(c1.next!=null && c2!=null){
            if(c1.val<=c2.val && c2.val<=c1.next.val){
                //insert c2 behind of c1
                ListNode tmp = c2.next;
                c2.next = c1.next;
                c1.next = c2;
                //advance both pointers
                c1 = c1.next;
                c2 = tmp;
            }
            else
                c1 = c1.next;
        }
        if(c1.next==null)
            c1.next = c2;
        return (l1.val<=l2.val?l1:l2);
    }
}