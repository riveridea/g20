/*

Median of Two Sorted Arrays:
https://leetcode.com/problems/median-of-two-sorted-arrays/

There are two sorted arrays A and B of size m and n
respectively. Find the median of the two sorted 
arrays. The overall run time complexity should be
O(log (m+n)).

对于一组有限个数的数据来说，它们的中位数是这样的一种数：这群数据
里的一半的数据比它大，而另外一半数据比它小。 计算有限个数的数据的
中位数的方法是：把所有的同类数据按照大小的顺序排列。如果数据的个数
是奇数，则中间那个数据就是这群数据的中位数；如果数据的个数是偶数，
则中间那2个数据的算术平均值就是这群数据的中位数。
*/

//http://fisherlei.blogspot.com/2012/12/leetcode-median-of-two-sorted-arrays.html
//http://www.acmerblog.com/leetcode-median-of-two-sorted-arrays-5330.html
//http://bangbingsyb.blogspot.com/2014/11/leetcode-median-of-two-sorted-arrays.html