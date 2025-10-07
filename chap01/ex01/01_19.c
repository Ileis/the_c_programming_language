#include <stdio.h>
#include <stdlib.h>

#define MAXLINELEN 1000

int get_line(char line[], int maxlen) {
    int len = 0;
    int c;
    while ((c = getchar()) != EOF && c != '\n' && len < (maxlen - 1)) line[len++] = c;
    if (c == '\n') line[len++] = c;
    line[len] = '\0';
    return len;
}

void reverse(char line[], int len) {
    if (line[len - 1] == '\n') --len;
    for (int i = 0; i < (len / 2); ++i) {
        char aux = line[i];
        line[i] = line[(len - 1) - i];
        line[(len - 1) - i] = aux;
    }
}

int main() {
    char line[MAXLINELEN];
    int len;
    while((len = get_line(line, MAXLINELEN)) > 0) {
        reverse(line, len);
        printf("%s", line);
        if (line[len - 1] != '\n') putchar('\n');
    }


    return EXIT_SUCCESS;
}
