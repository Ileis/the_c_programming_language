#include <stdio.h>

int get_line(char string[], int maxline)
{
    int c;
    int i = 0;
    while (--maxline > 0 && (c = getchar()) != EOF && c != '\n') string[i++] = c;
    if (c == '\n') string[i++] = c;
    string[i] = '\0';
    return i;
}
