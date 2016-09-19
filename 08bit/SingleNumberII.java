Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?


http://gongxuns.blogspot.com/2013/10/leetcode-single-number-ii.html

public class Solution {
    public int singleNumber(int[] A) {
        int single_number = 0;
        
        for (int i = 0; i < 32; ++i) {// assume dealing with int32.
            int bit = 0;
            for (int j = 0; j < A.length; ++j) {
                bit = (bit + ((A[j] >> i) & 1)) % 3;
            }
            single_number += (bit << i);
        }
        
        return single_number;        
    }
}


# http://blog.csdn.net/xiaozhuaixifu/article/details/12908869
public class Solution {
    public int singleNumber(int[] A) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
         if(A.length == 0)
            return 0;
        HashMap<Integer,Integer> hash = new HashMap<Integer,Integer>();
		for(int a : A)
		{
			if(hash.containsKey(a))
			{
				hash.put(a, hash.get(a) + 1);
			}
			else hash.put(a, 1);
		}
		for(int key : hash.keySet())
		{
			if(hash.get(key) == 1)
				return key;
		}
		return 0;
    }
}


http://www.cnblogs.com/feiling/p/3351379.html

Good, explanation:
http://www.cnblogs.com/daijinqiao/p/3352893.html

http://discuss.leetcode.com/questions/2811/single-number-and-single-number-ii