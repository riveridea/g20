/*
structure declarition: struct sname variable;
structure initialization: struct sname variable = {val1, val2, ...};

pass an entire structure as an argument to a function simply by writing 
the variable in the argument list when calling the function.

remember that C passes arguments by value. Therefore, any time you pass
a structure to a function, the function cannot make any permanent changes
to the variable itself. It can only change a copy that is created when the
function is called.

e.g. 
struct date today;

int juliandate(struct date caldate)
{
	int result;
	...
	return(result);
}

julian = juliandate(today)

so in this example, juliandate cannot make any changes to the variable
today, whose variable is passed to the function; it can only change a
copy of today that is placed in the variable caldate when the function
is called. 

*/
#include <stdio.h>

struct date {
    int month;
    int day;
    int year;
};


/*
Arrays of Structures:
Define an array of 100 elements called holidays. Each element of the
holidays array is of type struct date.
*/

struct date holidays[100];

// main function
int main() 
{
    struct date today;

    today.month = 3;
    today.day = 13;
    today.year = 1991;

    printf("%d/%d/%d\n", today.month, today.day, today.year - 1900);
}
