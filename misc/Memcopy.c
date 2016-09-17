/*
Implement the memcopy() function
*/

#include <stdio.h>

void *memcopy(void *dest, void *src, unsigned int count)
{
	if((NULL == dest) || (NULL == src))
		return NULL;

	char *d = (char *)dest;
	char *s = (char *)src;

	//Check for overlapping
	if ((d <= s) || d >= s + count) {
		while (count > 0) {
			*d++ = *s++;
			count--;
		}
	} else {
		while (count > 0) {
			*(d + count - 1) = *(s + count - 1);
			count--;
		}
	}

	return dest;
}

int main()
{
	char s[16] = "aabbcc";
	char d[16] = {0};

	printf("s is %s\n", s);
	printf("d is %s\n", d);

	memcopy(s+2, s, 4);

	printf("after memcopy, s is %s\n", s);

	return 0;
}


/*
How to make it faster?

1. It is also one of those functions that is rarely (when you get down to machine code) 
implemented using a loop: it's implementation often makes use of dedicated machine instructions, 
as a lot of machines are able to copy memory from one location to another using a fixed number 
of machine instructions (eg on some machines this amounts to pushing the two addresses and 
the size to specific machine registers, and then executing a single instruction for the 
actual operation) regardless of how much memory is being copied.

2. Use memcpy, but may have alignment problem
3. implemented in inline function by some assebly lanugage.
4.



*/