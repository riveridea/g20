/*
Two-Dimensional Arrays and Arrays to Pointers
*/

char days[7][10] = {
    "Sunday", "Monday", "Tuesday", "Wednesday",
    "Thursday", "Friday", "Saturday"
};

char *days[7] = {
    "Sunday", "Monday", "Tuesday", "Wednesday",
    "Thursday", "Friday", "Saturday"    
};

printf("%s\n", days[0]);

main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; ++i)
	{
		printf("%s\n", argv[i]);
	}
}

/* output
$ p2-13 one two three 125
p2-13
one
two
three
125
*/