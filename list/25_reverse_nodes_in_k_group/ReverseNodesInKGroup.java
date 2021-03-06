/*
25. Reverse Nodes in k-Group
https://leetcode.com/problems/reverse-nodes-in-k-group/

Given a linked list, reverse the nodes of a linked list k at a time 
and return its modified list. If the number of nodes is not a multiple 
of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.
Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5
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
    public ListNode reverseKGroup(ListNode head, int k) {
        if(k<=1 || head==null || head.next==null) return head;
        
        ListNode prev = new ListNode(0);
        prev.next = head;
        head = prev;
        
        ListNode cur=prev.next;
        while(cur!=null){
            int counter = k;
            while(cur!=null && counter>1){
                cur = cur.next;
                counter--;
            }
            
            if(cur!=null){
                cur=prev.next;
                counter=k;
                while(counter>1){
                    ListNode temp = cur.next;
                    cur.next=temp.next;
                    temp.next=prev.next;
                    prev.next=temp;
                    counter--;
                }
                prev = cur;
                cur = prev.next;
            }
        }
        
        return head.next;        
    }
}