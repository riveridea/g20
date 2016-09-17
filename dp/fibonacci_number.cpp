/*
Cracking the coding interview, 4th Question 8.1

Write a method to generate the nth Fibonacci number.

*/

class Solution {

public:

	int fibo(int n) {
		
		if (n < 0) {
			return -1;
		}

		if (n = 0) {
			return 0;
		}

		int a = 1, b = 1;

		for (int i = 3; i <= n; i++) {
			int c = a + b;;

			a = b;
			b = c;
		}

		return b;
	}
};


/*
Cracking the coding interview, 5th Question 9.1

A child is running up a staircase with n steps, and can hop either 1 step, 
2 steps, or 3 steps at at ime. Implement a method to count how many possible
ways teh child can run up teh stairs.

Also, see DP solution in DP folder
*/

class Solution {

public:
	/*
	The last move has three option: 
	1, from n-1th step
	2, from n-2th step
	3, from n-3th step
	*/
	int countWays(int n) {
		if (n < 0) {
			return 0;
		} else if (n == 0) {
			return 1;
		} else {
			return countWays(n-1) + countWays(n-2) 
				+ countWays(n-3);
		}
	}
};