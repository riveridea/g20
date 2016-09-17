/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/


# http://blog.csdn.net/whuwangyi/article/details/14146461
# http://gongxuns.blogspot.com/2013/11/leetcode-reorder-list.html
# http://www.programcreek.com/2013/12/in-place-reorder-a-singly-linked-list-in-java/

/* Java */

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
    public void reorderList(ListNode head) {
		if (head == null || head.next == null)
			return;

		// partition the list into 2 sublists of equal length
		ListNode slowNode = head, fastNode = head;
		while (fastNode.next != null) {
			fastNode = fastNode.next;
			if (fastNode.next != null) {
				fastNode = fastNode.next;
			} else {
				break;
			}
			slowNode = slowNode.next;
		}
		// 2 sublist heads
		ListNode head1 = head, head2 = slowNode.next;
		// detach the two sublists
		slowNode.next = null;

		// reverse the second sublist
		ListNode cur = head2, post = cur.next;
		cur.next = null;
		while (post != null) {
			ListNode temp = post.next;
			post.next = cur;
			cur = post;
			post = temp;
		}
		head2 = cur; // the new head of the reversed sublist

		// merge the 2 sublists as required
		ListNode p = head1, q = head2;
		while (q != null) {
			ListNode temp1 = p.next;
			ListNode temp2 = q.next;
			p.next = q;
			q.next = temp1;
			p = temp1;
			q = temp2;
		}        
    }
}