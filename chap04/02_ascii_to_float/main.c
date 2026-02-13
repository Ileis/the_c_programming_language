#include <stdio.h>
#define MAXLINE 100

int main()
{
    double sum, a_to_f(char []);
    char line[MAXLINE];
    int get_line(char [], int);

    sum = 0;
    while (get_line(line, MAXLINE) > 0)
        printf("\t%g\n", sum += a_to_f(line));
    return 0;
}
