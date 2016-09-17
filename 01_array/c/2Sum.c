/*
Q: Given an array of integers, find two numbers such 
   that they add up to a specific target number.

   The function twoSum should return indices of 
   the two numbers such that they add up to the target, 
   where index1 must be less than index2. Please note 
   that your returned answers (both index1 and index2) 
   are not zero-based.

   You may assume that each input would have exactly 
   one solution.

	Example: Input: numbers={2, 7, 11, 15}, target=9
		     Output: index1=1, index2=2
*/

/* Java */

/* 
* HashMap solution
* Time Complexity O(n)
* Space Complexity O(n)
*/

public class Solution {
    public int[] twoSum(int[] numbers, int target) {
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        
        int[] indexes = new int[2];
        
        for (int i = 0; i < numbers.length; i++) {
            if (map.containsKey(numbers[i])) {
                indexes[0] = map.get(numbers[i]) + 1;
                indexes[1] = i + 1;
                break;
            } else {
                map.put(target - numbers[i], i);
            }
        }
        
        return indexes;
        
    }
}

/*
* First Sort the array with O(nlgn)
* Then go through from both ends to middle. O(n).
* Important: if the order in the original array cannot
* be changed, the Hashtabel is the best solution.
*/

public class Solution {
    public int[] twoSum(int[] numbers, int target) {

    	// change the order! so the output indexes are
    	// not accurate, cannot pass OJ.
        Arrays.sort(numbers);
        
        int[] indexes = new int[2];
        int end = numbers.length-1;
        int start = 0;

        while (start < end) {
        	if (numbers[start] + numbers[end] == target) {
        		indexes[0] = start + 1;
        		indexes[1] = end +1;
        		break;
        	} else if (numbers[start] + numbers[end] < target) {
        		start++;
        	} else {
        		end--;
        	}
        }
        
        return indexes;
    }
}


== Additions From Google 

一个数组存放若干整数，一个数出现了奇数次，其余数出现了偶数次。找出出现奇数次的数是多少？


/* C */
/*
*  Old version
*/


#include <stdio.h>

#define TRUE 1
#define FALSE 0

int findTwoNumbers(int array[], int length, int sum, int &num1, &num2)
{
	if (array == NULL || length < 2)
		return FALSE;

	int *start = &array[0];
	int *end = &array[length - 1];

	while (start < end) {
		if ((*start + *end) == sum) {
			num1 = *start;
			num2 = *end;
			return TRUE;
		} else if ((*start + *end) < sum) {
			start++;
		} else if ((*start + *end) > sum) {
			end--;
		}
	}

	return FALSE;
}

int main()
{
	int a[6] = {1, 2, 4, 7, 11, 15};
	int a = 0;
	int b = 0;
	int sum = 15;
	printf("%d", findTwoNumbers(a, 6, sum, &a, &b));

	return 0;
}