/*
Container With Most Water:
Given n non-negative integers a1, a2, ..., an, where each represents a 
point at coordinate (i, ai). n vertical lines are drawn such that the 
two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which 
together with x-axis forms a container, such that the container contains 
the most water.

You may not slant the container.

OR
* set pointers to the beginning and the end of the array, then move
* the pointer correspondingly. for every step, record the current
* area and compare it with the max one. replace the MAX, if it is bigger.
*
* Every operation can ensure the maximum area it can get from the current
* position is recorded. like the Mathmatical Induction, the inital maximum
* area is recorded, too. So tha, this algorithm is correct.
*
* Running Time is O(n)
*/

/*
Idea: 
当从两边向中间考虑时，乘水的面积是由（两端较小的高度）×（两个板之间的宽度）决定的。
假定初始的盛水面积为ans=0，lh为左边的高度，rh为右边的高度，如果lh < rh, 则向右
运动，寻找第一个比当前lh大的左节点。同理，如果lh > rh，则向左运动，寻找第一个比
前rh大的右节点。

*/


class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        
        if (height.size() <= 1) {
            return maxArea; // 0
        }
        
        int i = 0;
        int j = height.size() -1;
        
        while (i < j) {
            int area = 0;
            if (height[i] < height[j]) {
                area = height[i] * (j-i);
                i++;
            } else { // if height[i] == height[j]??
                area = height[j] * (j-i);
                j--;
            }
            
            if (area > maxArea) {
                maxArea = area;
            }
        }
        
        return maxArea;
    }
};