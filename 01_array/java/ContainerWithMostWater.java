/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/


/*
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


/* Java */

public class Solution {
    public int maxArea(int[] height) {
        
       int maxArea = 0;
       int i = 0;
       int j = height.length - 1;
    
       if(j <=0)
         return 0;
       
       while(i < j) {
          int area = 0;
          if(height[i] < height[j]){
              area = height[i]*(j-i);
              i++;
             
          }else {
             area = height[j]*(j-i);
             j--;
          }

          if(area > maxArea) 
          	 maxArea = area;
        }
        
        return maxArea;        
    }
}