#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000

int my_getline(char line[], int maxline);
void my_copy(char to[], char from[]);
int check_too_big_line(char line[], int maxline);

int main() {
    int len, max;
    char line[MAXLINE], longest[MAXLINE];
    max = 0;
    while ((len = my_getline(line, MAXLINE)) > 0) {
        len += check_too_big_line(line, len);
        if (len > max) {
            max = len;
            my_copy(longest, line);
        }
    }
    if (max > 0) {
        printf("%s", longest);
        if (longest[max - 1] != '\n') printf("\n");
        printf("%d\n", max);
    }

    return EXIT_SUCCESS;
}

int check_too_big_line(char line[], int len) {
    int c, count = 1;
    if (line[len - 1] != '\n')
        while ((c = getchar()) != '\n') ++count;
    return count;
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
