#include <stdio.h>

struct date {
    int month;
    int day;
    int year;
};

int main() 
{
    struct date today;

    today.month = 3;
    today.day = 13;
    today.year = 1991;

    printf("%d/%d/%d\n", today.month, today.day, today.year - 1900);
}
