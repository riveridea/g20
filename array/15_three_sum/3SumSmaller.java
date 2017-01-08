/*
3 Sum Smaller

Given an array of n integers nums and a target, find the number of index 
triplets i, j, k with 0 <= i < j < k < n that satisfy the condition 
nums[i] + nums[j] + nums[k] < target.

For example, given nums = [-2, 0, 1, 3], and target = 2.
Return 2. Because there are two triplets which sums are less than 2:
[-2, 0, 1]
[-2, 0, 3]
Follow up:
Could you solve it in O(n2) runtime?

Understand the problem:
The problem looks quite similar to the 3-sum. Thus we could still sort 
the array first and use two pointers. 

The only thing needs to take special care of is how to move the pointers. 
There are two cases to handle: 
  -- If A[i] + A[j] + A[k] < target, which means the numbers between j and 
     k are all less than target, because the array is sorted. Then we move 
     the j pointer forward. 
  -- If A[i] + A[j] + A[k] >= target, we move k pointer backward.
*/