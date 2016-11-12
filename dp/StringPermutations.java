9.5.txt

# Write a method to compute all permutations of a string of unique characters.

public class Solution {

	public ArrayList<String> getPerms(String str) {

		if (str == null) {
			return null;
		}

		ArrayList<String> result = new ArrayList<String>();

		if (str.length() == 0) {
			return result;
		}

		char[] chars = str.toCharArray();

		boolean[] visited = new boolean[chars.length];
		char[] buff = new char[chars.length];

		dfs(result, visited, buff, chars, 0);

		return result;

	}

	public void dfs(ArrayList<String> result, boolean[] visited, char[] buff, 
					char[] chars, int pos) {
		
		if (pos == chars.length) {
			result.add(new String(buff));
			return;
		}

		for (int i = 0; i < chars.length; i++) {
			if (visited[i] == false) {
				buff[pos] = chars[i];
				visited[i] = true;
				dfs(result, visited, buff, chars, pos+1);
				visited[i] = false;
			}
		}
	}

	public static void main(String[] args) {
		System.out.println(new Solution().getPerms("abcde"));
	}
}