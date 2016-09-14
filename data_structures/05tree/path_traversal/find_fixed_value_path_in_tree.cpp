/*
 在二元树中找出和为某一值的所有路径。
 给定一个根节点。

*/

 // use backtracking and recursion

 typedef struct TreeNode {
 	struct TreeNode *left;
 	struct TreeNode *right;
 	int value;
 } TreeNode;


 void printPath(TreeNode root, int sums)
 {
 	int path[MAX_HEIGHT];
 	helper(root, sum, path, 0);
 }

 void helper(TreeNode root, int sum, int path[], int top)
 {
 	path[top++] = root.data;
 	sum -= root.data;

 	if (root.left == NULL && root.right == NULL) {
 		if (sum == 0)
 			printPath(path, top);
 	} else {
 		if (root.left != NULL)
 			helper(root.left, sum, path, top);

 		if (root.right != NULL)
 			helper(root.right, sum, path, top);

 		top--;
 		sum += root.data;
 	}
 }

 /*
Given a binary tree and a sum, determine if the tree has a 
root-to-leaf path such that adding up all the values along 
the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 
which sum is 22.
*/

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
    public boolean hasPathSum(TreeNode root, int sum) {
        if (root == null) {
            return false;
        }
        
        if (root.left == null && root.right == null && root.val == sum) {
            return true;
        } else {
            return (hasPathSum(root.left, sum - root.val) ||
                    hasPathSum(root.right, sum - root.val));
        }
    }
};

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