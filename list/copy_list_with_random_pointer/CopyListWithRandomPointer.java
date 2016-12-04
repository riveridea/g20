/*
A linked list is given such that each node 
contains an additional random pointer which could 
point to any node in the list or null.

Return a deep copy of the list.
*/


/**
 * Definition for singly-linked list with a random pointer.
 */
class RandomListNode {
    int label;
    RandomListNode next, random;
    RandomListNode(int x) { this.label = x; }
};

class Solution {
    public RandomListNode copyRandomList(RandomListNode head) {
        if (head == null) {
            return null;
        }

        RandomListNode node = head;
        RandomListNode temp = null;

        //insert new node
        while (node != null) {
            temp = node.next;

            RandomListNode newNode = new RandomListNode(node.label);
            node.next = newNode;
            newNode.next = temp;

            node = temp;
        }

        //update new node's random
        node = head;
        while (node != null) {
            if (node.random != null) {
                node.next.random = node.random.next;
            }

            node = node.next.next;
        }

        // seperate two linked lists
        RandomListNode newHead = head.next;

        node = head;
        RandomListNode newNode = node.next;
        while (node != null) {
            node.next = newNode.next;
            if (newNode.next != null) {
                newNode.next = newNode.next.next; // node.next.next
            }

            node = node.next;
            if (node != null) {
                newNode = node.next;
            }
        }

        return newHead;
    }
}

public class CopyListWithRandomPointer {

    public static void main(String args[]) {
        
    }

}