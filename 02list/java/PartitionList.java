/*
Given a linked list and a value x, partition it such that all nodes
less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each
of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

CC150 2.4
*/



/* Java */

# set up two temp head, one is node(-1), the other is 
node(3).  all node less then pivot linked to node(-1),
otherwise, connected to node(3). then combine these two
links.



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
    public ListNode partition(ListNode head, int x) {
        ListNode root = new ListNode(-1);
        ListNode pivot = new ListNode(x);
        ListNode root_last = root, pivot_last = pivot;
    
        ListNode cur_node = head;
        while (cur_node != null) {
            ListNode next = cur_node.next;
            if (cur_node.val < x) {
                root_last.next = cur_node;
                root_last = cur_node;
            } else {
                pivot_last.next = cur_node;
                pivot_last = cur_node;
                pivot_last.next = null;
            }
            cur_node = next;
        }
        root_last.next = pivot.next;
    
        return root.next;        
    }
}