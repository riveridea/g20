/*
266 Palindrome_Permutation

Given a string, determine if a permutation of the string could 
form a palindrome.

For example, "code" -> False, "aab" -> True, "carerac" -> True.
*/

//利用count array統計每個字數出現的次數, 出現奇數次的最多只能有一個", 
//代碼如下,  時間複雜度是O(n), 空間複雜度是O(1)
public class Palindrome_Permutation {
    public boolean canPermutePlindrome(String s) {
        if (s == null) {
        	return false;
        }

        int n = s.length();

        if (n == 0 || n == 1) {
        	return true;
        }

        // assume char is from ASCII
        int[] count = new int[128];
        int odd = 0;

        for (int i = 0; i < n; i++) {
        	count[s.charAt(i)]++;

        	if (count[s.charAt(i)] % 2 == 1) {
        		odd++;
        	} else {
        		odd--;
        	}
        }

        return (odd == 0 || odd == 1) ? true : false;
    }

    // leverage HashMap
    public boolean canPermutePlindrome2(String s) {

    }

    public static void main(String[] args) {

    }
}