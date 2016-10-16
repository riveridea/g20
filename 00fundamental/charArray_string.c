#include <stdio.h>

// char word[] = {"hello"}
// stores the charactrs 'h', 'e', 'l', 'l' and 'o', plus a
// terminating null character into the word array.

main(0)
{
	char word[] = {"hello"};
	char *char_ptr;

	for (char_ptr = word; *char_ptr != '\0'; ++char_ptr)
	{
		printf("%c", *char_ptr);
	}

	printf("\n");
	printf("%s\n", word);
}