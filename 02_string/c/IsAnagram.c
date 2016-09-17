/*
判断两个字符串是不是 anagram
*/

#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define NO_OF_CHARS 256

int check_anagram(char *str1, char *str2)
{
	int count1[NO_OF_CHARS] = {0};
	int count2[NO_OF_CHARS] = {0};
	int i;

	for (i = 0; str1[i] && str2[i]; i++) {
		count1[str1[i]]++;
		count2[str2[i]]++;
	}

	if (str1[i] || str2[i]) {
		return FALSE;
	}

	for (i = 0; i < NO_OF_CHARS; i++) {
		if (count1[i] != count2[i]) 
			return FALSE;
	}

	return TRUE;
}

int main()
{
	char str1[] = "geeksforgeeks";
	char str2[] = "forgeeksgeeks";

	if (check_anagram(str1, str2))
		printf("Two strings are anagram of each other");

	return 0;
}


/*

bool areAnagram(char *str1, char *str2)
{
    // Create two count arrays and initialize all values as 0
    int count[NO_OF_CHARS] = {0};
    int i;
 
    // For each character in input strings, increment count in
    // the corresponding count array
    for (i = 0; str1[i] && str2[i];  i++)
    {
        count[str1[i]]++;
        count[str2[i]]--;
    }
 
    // If both strings are of different length. Removing this condition
    // will make the program fail for strings like "aaca" and "aca"
    if (str1[i] || str2[i])
      return false;
 
    // See if there is any non-zero value in count array
    for (i = 0; i < NO_OF_CHARS; i++)
        if (count[i])
            return false;
     return true;
}

*/