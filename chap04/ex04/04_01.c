#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 1000

int get_line(char line[], int max);
int rstrindex(char source[], char searchfor[]);

int main() {
    char pattern[] = "ould";
    char line[MAXLINE];
    int found = 0;
    int index;
    while (get_line(line, MAXLINE) > 0) {
        if ((index = rstrindex(line, pattern)) >= 0) {
            printf("%s", line);
            printf("index: %d\n", index);
            found++;
        }
    }
    return found;
}

int get_line(char line[], int max) {
    int c;
    int i = 0;
    while (--max > 0 && (c = getchar()) != EOF && c != '\n') line[i++] = c;
    if (c == '\n') line[i++] = c;
    line[i] = '\0';
    return i;
}

int rstrindex(char source[], char searchfor[]) {
    int i, j, k;
    int len = strlen(source);
    for (i = len - 1; i >= 0; --i) {
        for (j = i, k = 0; searchfor[k] != '\0' && source[j] == searchfor[k]; ++j, ++k);
        if (k > 0 && searchfor[k] == '\0') return i;
    }
    return -1;
}
