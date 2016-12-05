/*
234. Palindrome Linked List
https://leetcode.com/problems/palindrome-linked-list/

Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?

OR CC150 2.7.txt

# Implement a function to check if a linked list is a palindrome.

1. Reverse the list and compare
2. push the first half in the stack then compare,
3. recursive approach.
4. fast-slow pointers to reach the middle point of linked list,
then compare the first part and last part.

e.g. 0->1->2->1->0
*/

/**
 * Definition for singly-linked list.
 */
class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

class Solution {
    // recursive approach
    public boolean isPalindrome(ListNode head) {
        int length = 0;
        ListNode tmp = head;
        // get the length
        while (tmo != null) {
            length += 1;
            tmp = tmp.next;
        }

        return isPalindromeHelper(ListNode head, int length) {

        }
    }

    // create a new reversed list
    // time and space are O(n)
    public boolean isPalindrome2(ListNode head) {
        // basic case 1
        if (head == null) {
            return true;
        }

        // basic case 2
        if (head.next == null) {
            return true;
        }

        ListNode current = head;
        // now the new list
        ListNode anotherHead = new ListNode(head.val);

        while (current.next != null) {
            ListNode tmp = new ListNode(current.next.val);
            tmp.next = anotherHead;
            anotherHead = tmp;
            current = current.next;
        }

        // now we have another list with reverse order
        ListNode p1 = head;
        ListNode p2 = anotherHead;

        while (p1 != null) {
            if (p1.val != p2.val) {
                return false;
            }

            p1 = p1.next;
            p2 = p2.next;
        }

        return true;
    }

    // use a fast and slow pointers to get the center of the list,
    // then reverse the second list and compare two sublists.
    // The time is O(n) and space is O(1)

    
}