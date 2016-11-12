/*
A robot is located at the top-left corner of a m x n grid 
(marked 'Start' in the diagram below). The robot can only 
move either down or right at any point in time. The robot 
is trying to reach the bottom-right corner of the grid 
(marked 'Finish' in the diagram below).

How many possible unique paths are there?
Note: m and n will be at most 100.
*/

class Solution {

public:
	/*
    --dp[i][j]表示从起点到位置(i, j)的路径总数。
    --通项公式:
    由于只能向右和左走，所以对于(i, j)来说，
    只能从左边或上边的格子走下来：
    dp[i][j] = dp[i-1][j] + dp[i][j-1].

    对于网格最上边和最左边，则只能从起点出发直线走到，
    dp[0][j] = dp[i][0] = 1

    --确定计算的方向:
    计算方向从上到下，从左到右即可。可以用滚动数组实现。

	*/

	// verified by leetcode
	int uniquePaths(int m, int n) {
		if (m < 1 || n < 1) {
			return 0;
		}

		vector<int> dp(n, 1);

        // line by line
		for (int i = 1; i < m; i ++) {
			// column by column
			for (int j = 1; j < n; j++) {
				dp[j] = dp[j] + dp[j-1];
			}
		}

		return dp[n-1];
	}

};
// or http://blog.csdn.net/kenden23/article/details/17303497
//看起来想 google 面试的那题 
// http://www.programcreek.com/2014/05/leetcode-unique-paths-java/
// http://blog.csdn.net/linhuanmars/article/details/22126357
/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/

class Solution{

public:	
   int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if(obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0]==1) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> dp(n,1);
        for(int j=1; j<n; j++) {
            if(obstacleGrid[0][j]==1)
                dp[j] = 0;
            else
                dp[j] = dp[j-1];
        }
        
        for(int i=1; i<m; i++) {
            dp[0] = obstacleGrid[i][0]==1 ? 0 : dp[0];
            for(int j=1; j<n; j++) {
                dp[j] = obstacleGrid[i][j]==1 ? 0 : dp[j-1] + dp[j];
            }
        }
        return dp[n-1];
    }
};


// Same Question
/*
Cracking Coding Interview 5th, Question 9.2

Image a robot sitting on the upper left corner of an X by Y grid. The robot can
only move into two directions: right and down. How many possible paths are there
for the robot to go from (0,0) to (x, y)?

# Follow Up: 
Image certain spots are "off limits," such that the robot cannot step on them. 
Design an algorithm to find a path for the robot from the top left to the bottom
right.
*/
