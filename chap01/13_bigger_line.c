#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000

int my_getline(char line[], int maxline);
void my_copy(char to[], char from[]);

int main() {
    int len, max;
    char line[MAXLINE], longest[MAXLINE];
    max = 0;
    while ((len = my_getline(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            my_copy(longest, line);
        }
    }
    if (max > 0) printf("%s\n", longest);

    return EXIT_SUCCESS;
}

int my_getline(char line[], int maxline) {
    int c, i;
    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

void my_copy(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0') ++i;
}
