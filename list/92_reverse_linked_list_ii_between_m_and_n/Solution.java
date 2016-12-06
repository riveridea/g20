/*
92. Reverse Linked List II
https://leetcode.com/problems/reverse-linked-list-ii/

Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
*/

/**
 * Definition for singly-linked list.
 */

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

public class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        
    }
}




public class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        if( head==null | m==n) return head;
        
        ListNode start = new ListNode(0);
        start.next = head;
        head = start;
        n=n-m+1; 
        
        while(--m > 0 && start!=null) 
            start = start.next;
        if(start==null) 
            return head.next;
        
        ListNode cur = start.next;
        ListNode pre = null;
        ListNode nxt = null;
        
        while(cur!=null && n-->0) {
            nxt = cur.next;
            cur.next = pre;
            pre = cur;
            cur = nxt;
        }
        
        start.next.next = cur;
        ListNode t = start.next;
        start.next = pre;
        start = t;
        
        return head.next;
    }
}

http://blog.csdn.net/xudli/article/details/8584401



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
  public ListNode reverseBetween(ListNode head, int m, int n) {
    int index = 0;
    ListNode root = new ListNode(0);
    root.next = head;
    ListNode cur_node = root;
    ListNode pre_m_node = root, m_node = root;
    while (index < m) {
        index++;
        if (index == m) {
            pre_m_node = cur_node;
            m_node = cur_node.next;
        }
        cur_node = cur_node.next;
    }

    index++;
    cur_node = m_node.next;
    while (index <= n) {
        m_node.next = cur_node.next;
        cur_node.next = pre_m_node.next;
        pre_m_node.next = cur_node;
        cur_node = m_node.next;
        index++;
    }

    return root.next;
  }
}