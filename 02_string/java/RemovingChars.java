/*
Write an efficient function in Java that delete characters
from a String. Using the protype:

String removeChars(Strng str, String remove);

where any character existing in "remove" must be deleted from str.
*/

public class J9 {


	public static String removeChars(String str, String remove) {
		char[] s = str.toCharArray();
		char[] r = remove.toCharArray();

		boolean[] flags = new boolean[128];
		int len = r.length;
		int src, dst;

		for (src = 0; src < len; ++src) {
			flags[r[src]] = true;
		}

		src = 0;
		dst = 0;

		while (src < len) {
			if (!flags[(int)s[src]]) {
				s[dst++] = s[src];
			}

			++src;
		}

		return new String(s, o, dst);
	}
}