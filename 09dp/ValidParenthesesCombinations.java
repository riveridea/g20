9.6.txt

# Implement an algorithm to print all valid combinations of n-pairs of parentheses.

public class Solution {

	public ArrayList<String> generateParens(int count) {
		ArrayList<String> result = new ArrayList<String>();

		if (count <= 0) {
			return result;
		}

		dfs(result, "", count, count);

		return result;
	}

	public void dfs(ArrayList<String> result, String tmp, int leftCount, int rightCount) {
		if (leftCount == 0 && rightCount == 0) {
			result.add(tmp);
			return;
		}

		if (leftCount > 0) {
			dfs(result, tmp + "(", leftCount -1, rightCount);
		}

		if (leftCount < rightCount) {
			dfs(result, tmp + ")", leftCount, rightCount -1);
		}
		
	}

	public static void main(String[] args) {
		System.out.println(new Solution().generateParens(3));
	}
}