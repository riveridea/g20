/*
Write an efficient function to find the first nonrepeated character
in a string.
*/

import java.util.*;

public class FirstNonRepeatedChar {

	public static Character firstNonRepeated(String str) {
		Hashtable<Character, Object> charHash 
			= new Hashtable<Character, Object>();
		int length = str.length();
		Character c = null;
		Object seenOnce = new Object();
		Object seenTwice = new Object();

		for (int i = 0; i < length; i++) {
			c = new Character(str.charAt(i));
			Object o = charHash.get(c);

			if (null == o) {
				charHash.put(c, seenOnce);
			} else if (o == seenOnce) {
				charHash.put(c, seenTwice);
			}
		}

		for (int j = 0; j < length; j++) {
			c = new Character(str.charAt(j));

			if (charHash.get(c) == seenOnce) {
				return c;
			}
		}

		return null;
	}

	public static void main(String[] args) {

		String str = "total";
		System.out.println(firstNonRepeated(str));
	}

}