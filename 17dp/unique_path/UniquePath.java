/*
Cracking Coding Interview 5th, Question 9.2
Same with unique_path.cpp

Image a robot sitting on the upper left corner of an X by Y grid. The robot can
only move into two directions: right and down. How many possible paths are there
for the robot to go from (0,0) to (x, y)?

# Follow Up: Same with Unique_path follow_up

Image certain spots are "off limits," such that the robot cannot step on them. 
Design an algorithm to find a path for the robot from the top left to the bottom
right.

*/

----
public class Solution {
	public int robotPaths(int down, int right, String path) {
		path = path + down + ", " + right + " ";

		if (down == 0 && right == 0) {
			System.out.println(path);
			return 1;
		}

		int counter = 0;

		if (down == 0) {
			counter = robotPaths(down, right - 1, path);
		} else if (right == 0) {
			counter = robotPaths(down - 1, right, path);
		} else {
			counter = robotPaths(down, right - 1, path) + robot(down - 1, right, path);
		}

		return counter;
	}

	public static void main(String[] args) {
		int N = 3;
		System.out.println("Total possible paths: " 
							+ new Solution().robotPaths(N-1, N-1, ""));
	}
}


----
public class Solution {
	
	public ArrayList<String> robotPaths(int n) {
		ArrayList<String> pathList = new ArrayList<String>();
		getPaths(n, 1, 1, "", pathList);
		return pathList;
	}

	public void getPaths(int n, int i, int j, String path,
			ArrayList<String> pathList) {
		path += String.format(" (%d, %d)", i, j);

		if ( i == n && j == n) {
			pathList.add(path);
		} else if (i > n || j > n) {
			return;
		} else {
			getPaths(n, i+1, j, path, pathList);
			getPaths(n, i, j+1, path, pathList);
		}
	}

	public static void main(String[] args) {
		int N = 3;
		System.out.println("Total possible paths: " 
							+ new Solution().robotPaths(N));		
	}
}