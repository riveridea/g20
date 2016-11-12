9.3.txt

# A magic index in an array A[1 ... n-1] is defined to be an index such that
# A[i] = i. Given a sorted array of distinct integers, write a method to find
# a magic index, if one exists, in array A.

# Follow Up

# What if the values are not distinct?

-----
1. Brute Force

public int magicSlow(int[] array) {
	for (int i = 0; i < array.length; i++) {
		if (array[i] == i) {
			return i;
		}
	}

	return -1;	
}


----
2. Binary Search

public int magicFast(int[] array) {

	if (array == null || array.length == 0) {
		return -1;
	}

	return helper(array, 0, array.length -1);
}

public int helper(int[] array, int start, int end) {
	if (start < end) {
		return -1;
	}

	int mid = (start + end)/2;

	if (array[mid] == mid) {
		return mid;
	} else if (array[mid] < mid) {
		return helper(array, start, mid - 1);
	} else {
		return helper(array, mid + 1, end);
	}
}

----
3. Follow Up -- if the elements are not distinct?

public ArrayList<Integer> magicFast(int[] array) {
	if (array == null || array.length == 0) {
		return -1;
	}

	ArrayList<Integer> arrayList = new ArrayList<Integer>()
	return helper(array, 0, array.length - 1, arrayList);
}

public ArrayList<Integer> helper(int[] array, int start, int end, 
								ArrayList<Integer> results) {
	if (start < end) {
		return arrayList;
	}

	int mid = (start + end)/2;
	int midValue = array[mid];

	if (midValue == mid) {
		results.add(mid);
	} 

	int leftIndex = Math.min(mid-1, midValue);
	
}
