/*
128. Longest Consecutive Sequence
https://leetcode.com/problems/longest-consecutive-sequence/

Given an unsorted array of integers, find the length of 
the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is 
[1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

/*
Think as cluster merge, a single number is a length=1 cluster.

The key factors about a cluster is: lowest, highest, and length.
Map lowest and highest to length. To merge two neighbor clusters, only need to update it's new lowest and highest, with new length.
For every a[i], checking its neighbor a[i]-1 and a[i]+1 is enough.

*/


/* Java */

public class Solution {
    public int longestConsecutive(int[] a) {
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        int max = 1;
        for (int i : a) {
            if (map.containsKey(i)) continue;
            map.put(i, 1);
            if (map.containsKey(i - 1)) {
                max = Math.max(max, merge(map, i-1, i));
            }
            if (map.containsKey(i + 1)) {
                max = Math.max(max, merge(map, i, i+1));
            }
        }
        return max;
    }
    
    private int merge(HashMap<Integer, Integer> map, int left, int right) {
        int upper = right + map.get(right) - 1;
        int lower = left - map.get(left) + 1;
        int len = upper - lower + 1;
        map.put(upper, len);
        map.put(lower, len);
        return len;
    }
}


####
private int findConsecutive(HashMap<Integer, Boolean> map, int num, int step) {
    int len = 0;
    while (map.containsKey(num)) {
        ++len;
        map.put(num, true);
        num += step;
    }
    return len;
}

public int longestConsecutive(int[] nums) {
    HashMap<Integer, Boolean> map = new HashMap<Integer, Boolean>();
    // find all 
    for (int num : nums) {
        map.put(num, false);
    }
    // find longest seq
    int maxLen = 0;
    for (int num : nums) {
        if (!map.get(num)) {
            map.put(num, true);
            int len = 1 + findConsecutive(map, num-1, -1);
            len += findConsecutive(map, num+1, 1);
            maxLen = Math.max(maxLen, len);
        }
    }
    return maxLen;
}