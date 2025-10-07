#include <stdio.h>
#include <stdlib.h>

#define BUFFERLEN 1000
#define IN  1
#define OUT 0

int get_trimed_line(char line[], int maxline) {
    int c;
    int len = 0;
    int wc = 0;
    int state = OUT;
    while((c = getchar()) != EOF && c != '\n' && len < (maxline - 1)) {
        // if (len > 0 && (c == ' ' || c == '\t') && (line[len - 1] == ' ' || line[len - 1] == '\t'))
        if (len < 0 || (c != ' ' && c != '\t') || (line[len - 1] != ' ' && line[len - 1] != '\t')) line[len++] = c;
        // word counter
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            wc++;
        }
    }
    if (c == EOF) return -1;
    if (c == '\n') line[len++] = '\n';
    line[len] = '\0';
    if (wc == 0) {
        line[0] = '\0';
        len = 0;
    }
    return len;
}

int main() {
    char line[BUFFERLEN];
    while(get_trimed_line(line, BUFFERLEN) >= 0) printf("%s", line);

    return EXIT_SUCCESS;
}
