/*
237. Delete Node in a Linked List
2.3.txt
https://leetcode.com/problems/delete-node-in-a-linked-list/

Write a function to delete a node (except the tail) in the middle
 of a ingly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given 
the third node with value 3, the linked list should become 
1 -> 2 -> 4 after calling your function.

note: this problem cannot be solved if the node to be deleted 
is the last node in the linked list.
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
    public void deleteNode(ListNode node) {
        if (node == NULL || node.next == NULL) {
        	return;
        }

        ListNode nextNode = node.next;
        node.val = nextNode.val;
        node.next = nextNode.next;

        return;
    }
}

public class DeleteNodeinList {

	public static void main(String args[]) {

	}
}