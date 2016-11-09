/*
Given a binary tree and a sum, find all root-to-leaf paths 
where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
*/
---- dfs solution passed ---

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
    public ArrayList<ArrayList<Integer>> pathSum(TreeNode root, int sum) {
        ArrayList<ArrayList<Integer>> paths = new ArrayList<ArrayList<Integer>>();
        ArrayList<Integer> path = new ArrayList<Integer>();
        dfs(root, sum, paths, path);
        return paths;
    }
    
    public void dfs(TreeNode root, int sum, 
                    ArrayList<ArrayList<Integer>> paths,
                    ArrayList<Integer> path) {
        if (root == null) {
            return;
        }
        
        if (root.val == sum && root.left == null && root.right == null) {
            path.add(root.val);
            paths.add(new ArrayList<Integer>(path));
            path.remove(path.size() - 1);
            return;
        }
        
        path.add(root.val);
        dfs(root.left, sum-root.val, paths, path);
        dfs(root.right, sum-root.val, paths, path);
        path.remove(path.size() -1);
    }
};




------
/* Java */

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
    public ArrayList<ArrayList<Integer>> pathSum(TreeNode root, int sum) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
        if(root==null) return res;
        
        Stack<TreeNode> nodes = new Stack<TreeNode>();
        Stack<Integer> accSums = new Stack<Integer>();
        LinkedList<TreeNode> path = new LinkedList<TreeNode>();
        nodes.add(root);
        accSums.add(root.val);
        
        while(!nodes.isEmpty()){            
            TreeNode node = nodes.pop();
            Integer accSum = accSums.pop();
            path.add(node);
            
            if(node.left==null && node.right==null){
                if(accSum==sum){
                    res.add(getPath(path));
                }
                path.remove(path.size()-1);
                while(!nodes.isEmpty() && !path.isEmpty() && path.peekLast().right!=nodes.peek())
                    path.remove(path.size()-1);

            }
            if(node.right!=null){
                nodes.add(node.right);
                accSums.add(accSum+node.right.val);
            }
            
            if(node.left!=null){
                nodes.add(node.left);
                accSums.add(accSum+node.left.val);
            }
        }
        return res;
    }
    
    public ArrayList<Integer> getPath(LinkedList<TreeNode> s){
        ArrayList<Integer> res = new ArrayList<Integer>();
        for(TreeNode node:s){
            res.add(node.val);
        }
        return res;
    }
}