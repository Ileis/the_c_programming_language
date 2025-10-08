#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

int max;
char line[MAXLINE];
char longest[MAXLINE];

int get_line(void);
void copy(void);

int main() {
    int len;
    extern int max;
    extern char longest[];

    max = 0;
    while ((len = get_line()) > 0) {
        if (len > max) {
            copy();
            max = len;
        }
    }
    if (max > 0) printf("%s", longest);
    return EXIT_SUCCESS;
}

int get_line(void) {
    int c, len;
    extern char line[];
    for (len = 0; len < (MAXLINE - 1) && (c = getchar()) != EOF && c != '\n'; ++len) line[len] = c;
    if (c == '\n') line[len++] = c;
    line[len] = '\0';
    return len;
}

void copy(void) {
    extern char longest[];
    extern char line[];
    for (int i = 0; (longest[i] = line[i]) != '\0'; ++i);
}
