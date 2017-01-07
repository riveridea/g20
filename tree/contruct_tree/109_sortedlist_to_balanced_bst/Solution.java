/*
109 Convert Sorted List to Binary Search Tree:
https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

Given a singly linked list where elements are sorted in
ascending order, convert it to a height balanced BST.
*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public TreeNode sortedListToBST(ListNode head) {
        
    }
}

public class Solution {
    public TreeNode sortedListToBST(ListNode head) {
        int length = 0;
        ListNode runner = head;
        while (runner != null) {
            runner = runner.next;
            length++;
        }
        
        return sortedListToBSTHelper(head, 0, length-1);
    }
    
    public TreeNode sortedListToBSTHelper(ListNode head, int start, int end) {
        if (start > end)
            return null;
            
        int mid = start + (end - start)/2;
        ListNode tmp = head;
        
        for (int i = 0; i < mid; i++) {
            tmp = tmp.next;
        }
        
        TreeNode parent = new TreeNode(tmp.val);

        parent.left = sortedListToBSTHelper(head, start, mid-1);
        parent.right = sortedListToBSTHelper(head, mid+1, end);
        
        return parent;
    }
}




or save the list in array first

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; next = null; }
 * }
 */
/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public TreeNode sortedListToBST(ListNode head) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(head == null){
            return null;
        }
        int len = 0;
        ListNode p = head;
        while(p != null){
            len ++;
            p = p.next;
        }
        int[] num = new int[len];
        p = head;
        int i = 0;
        while(p != null){
            num[i++] = p.val;
            p = p.next;
        }
        
        return generate(num, 0, len - 1);
    }
    
    public TreeNode generate(int[] num, int start, int end){
        if(start > end){
            return null;
        }
        int mid = (start + end) / 2;
        TreeNode root = new TreeNode(num[mid]);
        root.left = generate(num, start, mid - 1);
        root.right = generate(num, mid + 1, end);
        return root;
    }
}