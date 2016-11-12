/*
246. Graph Valid Tree

Given n nodes labeled from 0 to n - 1 and a list of undirected edges 
(each edge is a pair of nodes), write a function to check whether 
these edges make up a valid tree.

For example:

Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], returntrue.

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], returnfalse.

Hint:

Given n = 5 andedges = [[0, 1], [1, 2], [3, 4]], what should your return? 
Is this case a valid tree?
According to the definition of tree on Wikipedia: “a tree is an undirected 
graph in which any two vertices are connected byexactly one path. In other 
words, any connected graph without simple cycles is a tree.”
Note: you can assume that no duplicate edges will appear in edges. Since 
all edges are undirected, [0, 1] is the same as [1, 0] and thus will not 
appear together in edges.

题解：
最简便的写法是Quick-Union，参见Coursera Algorithm Part I.
但效率未必是最高的，因为如果数据量很大的时候，寻找parent会很费时。
*/

public class Solution {
	public boolean validTree(int n, int[][] edges) {
		
	}
}