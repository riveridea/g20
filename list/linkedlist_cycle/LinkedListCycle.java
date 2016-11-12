/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/


/*
Similar Question: Problem -6
Can we use hashing technique for solving this problem? Yes
Can we use sorting technique?
Can we solve the problem in O(n)?

*/


/* Java */

/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;a
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode fast = head;
        ListNode slow = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;

            if (slow == fast) {
                break;
            }
        }

        return !(fast == null || fast.next == null);
    }
}


/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space?

Follow up: how do you remove the cycle? P62

CC 150 2.6

Follow up:
If there is a cycle, find the length of the loop.

*/

// CC150 java solution

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
    public ListNode detectCycle(ListNode head) {

        if (head == null||head.next == null) {
            return null;
        }

        ListNode node1 = head;
        ListNode node2 = head;

        while (node2 != null && node2.next != null) {
            node1 = node1.next;
            node2 = node2.next.next;

            if (node1 == node2) {
                break;
            }
        }

        if (node2.next == null) {
            return null;
        }

        node1 = head;

        while (node1 != node2) {
            node1 = node1.next;
            node2 = node2.next;
        }

        return node2;
    }
}
