https://leetcode.com/problems/valid-anagram/

/*
判断两个字符是不是 anagram
*/

public static boolean anagram(String a, String b)
{
	if (a.length() != b.length()) {
		return false;
	}

	int letters[] = new int[256];

	if (a == " " && b == " ") {
		return true;
	}

	for (int i = 0; i < letters.length; i++) {
		letters[i] = 0;
	}

	for (char c: a.toCharArray()) {
		++letters[c];
	}

	for (char c: b.toCharArray()) {
		if (letters[c] == 0) {
			return false;
		}

		--letters[i];
	}

	for (int i = 0; i < letters.length; i++) {
		if (letters[i] != 0) {
			return false;
		}
	}

	return true;
}

/*
1.8.txt

public class Solution {
    public boolean isRotation(String s1, String s2) {
    	int len = s1.length();
    	
    	if (len == s2.length() && len > 0) {
    		String s1s1 = s1 + s2;
    		return s1s1.contains(s2);
    	}
    	
    	return false;
    }

  
    public static void main(String[] args) {

    	System.out.println(new Solution().isRotation("apple", "pleap"));   	
    }
}
*/
