/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/


/* Java */


/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
public class Solution {
    public ArrayList<Interval> merge(ArrayList<Interval> intervals) {
        ArrayList<Interval> res = new ArrayList<Interval>();
        if (intervals == null || intervals.isEmpty())
            return res;
    
        Comparator<Interval> comparator = new Comparator<Interval>() {
            @Override
            public int compare(Interval i1, Interval i2) {
                if (i1.start < i2.start)
                    return -1;
                else if (i1.start > i2.start)
                    return 1;
                else {
                    if (i1.end < i2.end)
                        return -1;
                    else if (i1.end > i2.end)
                        return 1;
                    else
                        return 0;
                }
            }
        };
        Collections.sort(intervals, comparator);
    
        for (int i = 0; i < intervals.size(); i++) {
            Interval cur = intervals.get(i);
            if (res.isEmpty()) {
                res.add(cur);
            } else {
                Interval last = res.get(res.size() - 1);
                if (last.end >= cur.start) {
                    last.end = Math.max(last.end, cur.end);
                } else {
                    res.add(cur);
                }
            }
        }
    
        return res;        
    }
}