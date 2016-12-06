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
    public ListNode reverseListRec (ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode subListHead = head.next;
        head.next = null;

        // smaller-size problem
        ListNode reversedListHead = reverseListRec(subListHead);
        subListHead.next = head;

        return reversedListHead;
    }

    // iteratively
    public ListNode reverseListIte (ListNode head) {
        // base case 1 & 2
        if (null == head || null == head.next) {
            return head;
        }

        ListNode reversedListHead = null;
        ListNode nextNode = null;

        while (head != null) {
            nextNode = head.next;
            head.next = reversedListHead;
            reversedListHead = head;
            head = nextNode;
        }

        return reversedListHead;
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

        System.out.println("Do it recursively:");
        ListNode head1 = s.buildList();
        s.printList(head1);
        ListNode reversedListHead1 = s.reverseListRec(head1);
        s.printList(reversedListHead1);

        System.out.println("Do it iteratively:");
        ListNode head2 = s.buildList();
        s.printList(head2);
        ListNode reverseListHead2 = s.reverseListIte(head2);
        s.printList(reverseListHead2);
    }
}
