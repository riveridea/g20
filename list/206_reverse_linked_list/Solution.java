/*
206. Reverse a singly linked list.
https://leetcode.com/problems/reverse-linked-list/

A linked list can be reversed either iteratively or recursively. 
Could you implement both?
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
    // recursively
    public ListNode reverseList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode second = head.next;
        head.next = null;
        ListNode sublistHead = reverseList(second);
        sublistHead.next = head;

        return sublistHead;
    }

    public ListNode buildList() {

        ListNode node1 = new ListNode(1);
        ListNode node2 = new ListNode(2);
        ListNode node3 = new ListNode(3);
        ListNode node4 = new ListNode(4);

        node1.next = node2;
        node2.next = node3;
        node3.next = node4;

        return node1;
    }

    public void printList(ListNode head) {

        while (head != null) {
            System.out.print(head.val);
            System.out.print("->");
            head = head.next;
        }

        System.out.print("null");
        System.out.println();
    }

    public static void main (String args[]) {
        Solution s = new Solution();
        ListNode head = s.buildList();
        s.printList(head);
    }
}
