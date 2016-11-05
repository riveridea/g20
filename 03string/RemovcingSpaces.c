/*
write a C function to remove spaces from a string.
The function header should be
void removeSpaces(char *str)

ie, "abc de" -> "abcde"
*/


#include <stdio.h>

int removeSpace(char *str) {

	if (NULL == str|| strlen(str) > 80)
		return 0;

	char *p = str;

	while (*p) {
		if (*p == ' ') {
			p++;
		} else {
			*str++ = *p++;
		}
	}

	*str = '\0';

    return 1;
}