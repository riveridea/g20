/*
11. Container With Most Water
https://leetcode.com/problems/container-with-most-water/

Given n non-negative integers a1, a2, ..., an, where each represents a 
point at coordinate (i, ai). n vertical lines are drawn such that the 
two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which 
together with x-axis forms a container, such that the container contains 
the most water.

Note: You may not slant the container.
*/


/*
* set pointers to the beginning and the end of the array, then move
* the pointer correspondingly. for every step, record the current
* area and compare it with the max one. replace the MAX, if it is bigger.
*
* Every operation can ensure the maximum area it can get from the current
* position is recorded. like the Mathmatical Induction, the inital maximum
* area is recorded, too. So that, this algorithm is correct.
*
* Running Time is O(n)
*/


/* Java */

public class ContainerWithMostWater {
    public int maxArea(int height[]) {
        
        int maxArea = 0;
        int right = 0;
        int left = height.length - 1;
        
        if (left <= 0) {
            return 0;
        }
        
        while (right < left) {
            int tempArea = 0;
            
            if (height[right] < height[left]) {
                tempArea = height[right] * (left - right);
                // move right to left, to see whether we can
                // find a higher bar
                right++;
            } else {
                tempArea = height[left] * (left - right);
                left--;
            }
            
            if (tempArea > maxArea) {
                maxArea = tempArea;
            }
        }
        
        return maxArea;
    }

    public static void main(String args[]) {
        int height[] = new int[4];
        height[0] = 1;
        height[1] = 3;
        height[2] = 2;
        height[3] = 4;

        ContainerWithMostWater solution = new ContainerWithMostWater();

        System.out.println("The most water is: " + solution.maxArea(height));
    }
}