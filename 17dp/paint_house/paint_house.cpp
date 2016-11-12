/*
There are a row of n houses, each house can be painted with 
one of the three colors: red, blue or green. The cost of 
painting each house with a certain color is different. 
You have to paint all the houses such that no two adjacent 
houses have the same color.

The cost of painting each house with a certain color is 
represented by a n x 3 cost matrix. For example, 
costs[0][0] is the cost of painting house 0 with color 
red; costs[1][2] is the cost of painting house 1 with 
color green, and so on... Find the minimum cost to 
paint all houses.
*/

class Solution {  
public:  
    int minCost(vector<vector<int>>& costs) {  
        if(costs.size() == 0)  
            return 0;  
        vector<vector<int>> cost(costs.size(), vector<int>(3, 0));  
        cost[0][0] = costs[0][0];  
        cost[0][1] = costs[0][1];  
        cost[0][2] = costs[0][2];  
        int i;  
        for(i = 1; i < costs.size(); i++) {  
            cost[i][0] = min(cost[i-1][1], cost[i-1][2]) + costs[i][0];  
            cost[i][1] = min(cost[i-1][0], cost[i-1][2]) + costs[i][1];  
            cost[i][2] = min(cost[i-1][0], cost[i-1][1]) + costs[i][2];  
        }  
        return min(cost[i-1][0], min(cost[i-1][1], cost[i-1][2]));  
    }  
};