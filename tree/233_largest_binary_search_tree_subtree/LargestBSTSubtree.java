/*
Leetcode: 333. Largest BST Subtree

Given a binary tree, find the largest subtree which is a 
Binary Search Tree (BST), where largest means subtree with 
largest number of nodes in it.
Note:
A subtree must include all of its descendants.
Here's an example:
    10
    / \
   5  15
  / \   \ 
 1   8   7
The Largest BST Subtree in this case is the highlighted one. 
The return value is the subtree's size, which is 3.
Hint:
You can recursively use algorithm similar to 98. Validate Binary 
Search Tree at each node of the tree, which will result in O(nlogn) 
time complexity.
Follow up:
Can you figure out ways to solve it with O(n) time complexity?
*/

class Wrapper{
    int size;
    int lower, upper;
    boolean isBST;
 
    public Wrapper(){
        lower = Integer.MAX_VALUE;
        upper = Integer.MIN_VALUE;
        isBST = false;
        size = 0;
    }
} 
public class Solution {
    public int largestBSTSubtree(TreeNode root) {
        return helper(root).size;
    }
 
    public Wrapper helper(TreeNode node){
        Wrapper curr = new Wrapper();
 
        if(node == null){
            curr.isBST= true;
            return curr;
        }
 
        Wrapper l = helper(node.left);
        Wrapper r = helper(node.right);
 
        //current subtree's boundaries
        curr.lower = Math.min(node.val, l.lower);
        curr.upper = Math.max(node.val, r.upper);
 
        //check left and right subtrees are BST or not
        //check left's upper again current's value and right's lower against current's value
        if(l.isBST && r.isBST && l.upper<=node.val && r.lower>=node.val){
            curr.size = l.size+r.size+1;
            curr.isBST = true;
        }else{
            curr.size = Math.max(l.size, r.size);
            curr.isBST  = false;
        }
 
        return curr;
    }
}