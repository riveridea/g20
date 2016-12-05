/*
19. Remove Nth Node From End of List
https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
 */

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
        next = null;
    }
}

class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if (head == null || n < 1) {
            return null;
        }
        
        ListNode first = head;
        ListNode second = head;
        
        // move the first node pointer to the nth node
        int i = 1;
        
        while (i < n) {
            if (first.next != null) {
                first = first.next;
                i++;
            } else {
                // the linkedlist is not long enough
                return null;
            }
        }
        
        // now we have a pointer pointing to nth element in the list
        // we happen to have n-1 elements in the list
        if (first == null) {
            return null;
        }
        
        while (first.next != null) {
            // move first towards the end of the list
            // when first reaches the end, the second
            // will point to the nth from the listend
            first = first.next;
            second = second.next;
        }
        
        return second;
    }
}

public class RemoveNthNodeFromEndofList {


    public ListNode buildList() {

        ListNode node1 = new ListNode(1);
        ListNode node2 = new ListNode(2);
        ListNode node3 = new ListNode(3);
        ListNode node4 = new ListNode(4);
        ListNode node5 = new ListNode(5);

        node1.next = node2;
        node2.next = node3;
        node3.next = node4;
        node4.next = node5;

        return node1;
    }


    public void printList(ListNode head) {
        if (head == null) {
            return;
        }

        while (head.next != null) {
            System.out.print(head.val);
            System.out.print("->");
        }

        System.out.print("null");

    }
 
    Solution solution = new Solution();
    ListNode head = null;
    RemoveNthNodeFromEndofList test = new RemoveNthNodeFromEndofList();
 
    public static void main(String args[]) {

        head = test.buildList();
        test.printList(head);
    }
}