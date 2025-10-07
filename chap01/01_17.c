#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000
#define PRINTLINELEN 80

int my_getline(char line[], int maxline);

int main() {
    char line[MAXLINE];
    int len;
    for (int i = 0; i < PRINTLINELEN; ++i) printf("-");
    printf("\n");
    while ((len = my_getline(line, MAXLINE)) > 0)
        if (len >= PRINTLINELEN) printf("%s", line);
    return EXIT_SUCCESS;
}

int my_getline(char line[], int maxline) {
    int c, len = 0;
    while ((c = getchar()) != EOF && c != '\n' && len < maxline - 1)
        line[len++] = c;
    if (c == '\n') line[len++] = c;
    line[len] = '\0';
    return len;
}
