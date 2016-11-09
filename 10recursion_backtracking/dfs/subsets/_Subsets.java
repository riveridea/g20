9.4.txt

# Write a method to return all subsets of a set.


----

public ArrayList<ArrayList<Integer>> getSubSets(int[] a) {
	
	ArrayList<ArrayList<Integer>> subsets = new ArrayList<ArrayList<Integer>>();
	ArrayList<Integer> set = new ArrayList<Integer>();

	subsets.add(set);
	Arrays.sort(a);

	dfs(set, subsets, a, 0);

	return subsets;
}

public void dfs(ArrayList<Integer> set, ArrayList<ArrayList<Integer>> subsets, int[] a, int pos) {
	
	for (int i = pos; i < a.length; i++) {
		set.add(a[i]);
		subsets.add(new ArrayList<Integer>(set));
		dfs(set, subsets, a, i+1);
		set.remove(set.size() - 1);
	}
}