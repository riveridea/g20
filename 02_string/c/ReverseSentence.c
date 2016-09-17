/*
write a function that reverse the order of the words in a strng
*/

void reverseWords(char str[])
{
	int start = 0, end = 0, length;
	length = strlen(str);

	reverseString(str, start, length-1);

	while (end < length) {
		if (str[end] != ' ') {
			start = end;
			
			while (end < length && str[end] != ' ') {
				end++;
			}

			end--;
			reverseString(str, start, end);
		}

		end++;
	}
}

void reverseString(char str[], int start, int end)
{
	char temp;

	while (end > start) {
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;

		start++;
		end--;
	}
}