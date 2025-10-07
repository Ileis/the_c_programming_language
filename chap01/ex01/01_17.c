#include <stdio.h>
#include <stdlib.h>

#define PRINTLINELEN 5
#define BUFFERLEN 1000

int my_getline(char line[], int maxlen) {
    int c, len = 0;
    while ((c = getchar()) != EOF && c != '\n' && len < (maxlen - 1))
        line[len++] = c;
    if (c == '\n') line[len++] = c;
    line[len] = '\0';
    return len;
}

int main() {
    char line[BUFFERLEN];
    int len;
    while((len = my_getline(line, BUFFERLEN)) > 0) {
        if (len >= PRINTLINELEN) printf("%s", line);
    }

    return EXIT_SUCCESS;
}
