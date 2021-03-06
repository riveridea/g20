/*
57. Insert Interval
https://leetcode.com/problems/insert-interval/

Given a set of non-overlapping intervals, insert a new interval into the 
intervals (merge if necessary). You may assume that the intervals were 
initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as 
[1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/

/* Java */

/**
 * Definition for an interval.
 */
 public class Interval {
     int start;
     int end;
     Interval() { start = 0; end = 0; }
     Interval(int s, int e) { start = s; end = e; }
 }

/*
 * Solution 
 */
class Solution {
    public ArrayList<Interval> insert(ArrayList<Interval> intervals, Interval newInterval) {
 
        Interval temp = newInterval;
        ArrayList<Interval> list = new ArrayList<Interval>();
        
        for(Interval i : intervals){
            if(i.end < temp.start){
                list.add(i);
            } else if(i.start > temp.end){
                list.add(temp);
                temp = i;
            } else{
                temp = new Interval(Math.min(temp.start, i.start), Math.max(temp.end, i.end));
            }
        }
        
        list.add(temp);
        
        return list;
    }
}

public class InsertInterval {

    public static void main(String args[]) {

    }
}