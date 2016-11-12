/*
207. Course Schedule
https://leetcode.com/problems/course-schedule/

There are a total of n courses you have to take, labeled from
0 to n - 1. Some courses may have prerequisites, for example 
to take course 0 you have to first take course 1, which is 
expressed as a pair: [0,1]. Given the total number of courses 
and a list of prerequisite pairs, is it possible for you to 
finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you 
should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you 
should have finished course 0, and to take course 0 you should 
also have finished course 1. So it is impossible.

Note:
The input prerequisites is a graph represented by a list of edges, 
not adjacency matrices. Read more about how a graph is represented.

click to show more hints.

Hints:
This problem is equivalent to finding if a cycle exists in a 
directed graph. If a cycle exists, no topological ordering exists 
and therefore it will be impossible to take all courses.
Topological Sort via DFS - A great video tutorial (21 minutes) on 
Coursera explaining the basic concepts of Topological Sort.
Topological sort could also be done via BFS.
*/

public class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        // adjacency list is a linked list
        List<Set> nodes = new ArrayList<Set>();

        for (int i = 0; i < numCourses; i++) {
        	nodes.add(new HashSet<Integer>());
        }

        // fill the adjaceny list with the prerequistes
        // prerequisites is n-dim array of 2-dim array, 
        for (int i = 0; i < prerequisites.length; i++) {
        	// get the course IDs, which will be the requirement for 
        	// other courses. then put all the courses after it into
        	// a hash set
        	nodes.get(prerequisites[i][1]).add(prerequisites[i][0]);
        }

        // count the after-course for each courses, from 0 to n-1
        int[] outDegree = new int[numCourses];

        for (int i = 0; i < numCourses; i++) {
        	Set set = nodes.get(i);
        	// assume, i mean course ith, outDegree[i] means
        	// how many other courses use it as the prerequiste
            Iterator<Integre> it = set.iterator();

            while (it.hasNext()) {
            	outDegree[it.next()]++;
            }
        }

        // use BFS to remove a ready-to-take course once per time
        for (int i = 0; i < numCourses; i++) {
        	// find a course, which doesn't need any other courses,
        	// to begin with
        	int courseNumber = 0;
        	for (; courseNumber < numCourses; j++) {
        		if (outDegree[j] == 0) {
        			// find one, and remove
        			break;
        		}
        	}

        	if (courseNumber == numCourses) {
        		// because every course will need some course else
        		// there is a cycle, no result found, return false
        		return false;
        	}

        	// otherwise decrease the outDegree
        	outDegree[courseNumber] =- 1;

        	Set set = nodes.get(courseNumber);
        	Iterator<Integer> it = set.iterator();

        	while (it.hasNext()) {
        		outDegree[it.next()]--;
        	}
        }

        return true;
    }
}