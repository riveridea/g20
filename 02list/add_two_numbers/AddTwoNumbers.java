/*
2. Add Two Numbers
https://leetcode.com/problems/add-two-numbers

You are given two linked lists representing two non-negative 
numbers. The digits are stored in reverse order and each of 
their nodes contain a single digit. Add the two numbers and 
return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

------
2.5 You have two numbers represented by a linked list,
where each node contains a single digit. The digits
are stored in reverse order, such that the 1's digit is
at the head of the list. Write a function that adds the 
two numbers and returns the sum as a linked list.

E.g. inpu : (3->1->5) + (5->9->2)
output: (8->0->8)

513 + 295 = 808
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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {

        ListNode tmpHead = new ListNode(0);
        int carry = 0;
        ListNode lastNode = tmpHead;
        
        do {            
            int sum = carry;

            if(l1 != null){
                sum += l1.val;
                l1 = l1.next;
            }

            if(l2 != null){
                sum += l2.val;
                l2 = l2.next;
            }

            lastNode.next = new ListNode(sum % 10);            
            carry = sum / 10;            
            lastNode = lastNode.next;
    
        } while(l1 != null || l2 != null || carry > 0);
            return tmpHead.next;
    }
}




// initially, carry = 0
public class J8 {

	public static LinkedListNode addLists(LinkedListNode l1,
											LinkedListNode l2,
											int carry) {
		LinkedListNode result = new LinkedListNode(null, null, carry);
		int value = carry;

		if (l1 != null) {
			value += l1.data;
		}

		if (l2 != null) {
			value += l2.data;
		}

		result.data = value % 10;

		if (l1 != null || l2 != null || value >= 10) {
			LinkedListNode more = addList(l1 == null ? null : l1.next,
											l2 == null ? null : l2.next,
											value >= 10 ? 1 : 0);
			result.setNext(more);
		}
	
		return result;
	}

}
