/*
Pointers to Functions
*/

int leapyear (int year);
int (*fnptr) (int);

result = (*fnptr) (2000);

int fno (void);
int fno1 (void);
int fno2 (void);

static int (*dispatch[])(void) = {
	fn0, fn1, fn2
};

// to call the funtion indicated by the variable index,
// you write:

(*dispatch[index])();

/*
Define a data structure called command that contains two members.
The first member can be a pointer to the name of the command; the
second can be a pointer to the corresponding function to call.
*/

struct command {
	char *name;
	int (*function) (void);
};

// set up a table containing all of your command names and 
// corresponding functions to be called:

struct command dispatch[] = {
    {"add", addentry},
    {"calc", calcvals},
    {"delete", delentry},
    {"list", listdb},
    {"quit", quit},
    {"update", updentry}
};


/*
The function execute takes a character pointer as its argument. This presumably
points to a command read from the terminal. The function searches the 
dispatch table until it finds a match, and then calls the correspoing function.
execute returns the value returned by that function as its return value as
well. If no match is found, then execute returns UNKNOWNCMD (assume here that
none of the functions called by execute will return a value of UNKNOWNCMD).
The function also takes the dispatch table and the number of entries in the
table as arguments.	
*/

#define UNKNOWNCMD -1

int execute (char *typedcmd, struct command dispatch[], int numcmds)
{
	int i, fnresult = UNKNOWNCMD;

	for (i = 0; i < numcmds; ++i)
	{
		if (strcmp (typedcmd, dispatch[i].name) == 0)
		{
			fnresult = (*dispatch[i]function) ();
			break;
		}
	} 

	return (fnresult);
}


// Program 2-15
#include <stdio.h>

#define QUITCMD 999
#define OKCMD 0
#define UNKNOWNCMD -1

struct command {
	char *name;
	int (*function)(void)
};

main()
{
	char buf[81];

	int status;
	int addentry(void), calcvals(void), delentry(void),
	    listdb(void), quit(void), updentry(void);

	struct command dispatch[] = {
        {"add", addentry},
        {"calc", calcvals},
        {"delete", delentry},
        {"list", listdb},
        {"quit", quit},
        {"update", updentry}
    };

    int entries = sizeof(dispatch)/sizeof(struct command);

    do 
    {
         printf("\nEnter your command: ");
         scanf("%s", buf);
         status = execute(buf, dispatch, entries);

         if (status == UNKNOWNCMD) 
         {
         	printf("Unknown command: %s\n", buf);
         }
    } while(status != QUITCMD);
}

int addentry (void)
{
    printf("in addentry\n");
    return OKCMD;
}

int calcvals (void)
{
    printf("in calcvals\n");
    return OKCMD;
}

int delentry (void)
{
    printf("in delentry\n");
    return OKCMD;
}

int listdb (void)
{
    printf("in listdb\n");
    return OKCMD;
}

int quit (void)
{
    printf("in quit\n");
    return OKCMD;
}

int updentry (void)
{
    printf("in updentry\n");
    return OKCMD;
}
