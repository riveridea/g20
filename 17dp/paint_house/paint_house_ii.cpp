/*
There are a row of n houses, each house can be painted with one 
of the k colors. The cost of painting each house with a certain 
color is different. You have to paint all the houses such that 
no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented 
by a n x k cost matrix. For example, costs[0][0] is the cost of 
painting house 0 with color 0; costs[1][2] is the cost of painting 
house 1 with color 2, and so on... Find the minimum cost to paint 
all houses.

Note:
All costs are positive integers.

Follow up:
Could you solve it in O(nk) runtime?
*/

class Solution {  
public:  
    int minCostII(vector<vector<int>>& costs) {  
        if(costs.size() == 0)  
            return 0;  
              
        vector<vector<int>> cost(costs.size(), vector<int>(costs[0].size(), 0));  
        for(int i = 0; i < costs[0].size(); i++)  
            cost[0][i] = costs[0][i];  
              
        int i = 1;  
        while(i < costs.size()) {  
            int s = INT_MAX;  
            pair<int, int> m;  
            m.first = 0;  
            m.second = INT_MAX;  
            for(int j = 0; j < costs[0].size(); j++) {  
                if(cost[i-1][j] <= m.second) {  
                    s = m.second;  
                    m.first = j;  
                    m.second = cost[i-1][j];  
                } else if(cost[i-1][j] < s) {  
                    s = cost[i-1][j];  
                }  
            }  
            for(int j = 0; j < costs[0].size(); j++) {  
                int c = 0;  
                if(m.second == s) {  
                    c = s;  
                } else if(j == m.first) {  
                    c = s;  
                } else {  
                    c = m.second;  
                }  
                cost[i][j] = c + costs[i][j];  
            }  
            i++;  
        }  
        int result = INT_MAX;  
        for(int k = 0; k < costs[0].size(); k++) {  
            if(cost[i-1][k] < result)  
                result = cost[i-1][k];  
        }  
        return result;  
    }  
};