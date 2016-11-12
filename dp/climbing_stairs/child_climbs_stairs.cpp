/*
Cracking the coding interview, 5th Question 9.1

A child is running up a staircase with n steps, and can hop either 1 step, 
2 steps, or 3 steps at at ime. Implement a method to count how many possible
ways teh child can run up teh stairs.
*/

class Solution {

public:
	/*
	The last move has three option: 
	1, from n-1th step
	2, from n-2th step
	3, from n-3th step
	*/
	int countWaysDP(int n, int[] map) {
		if (n < 0) {
			return 0;
		} else if (n == 0) {
			return 1;
		} else if (map[n] > -1) {
			return map[n];
		} else {
			map[n] = countWaysDP(n-1, map) +
					 countWaysDP(n-2, map) +
					 countWaysDP(n-3, map);

			return map[n];
		}
	}

};