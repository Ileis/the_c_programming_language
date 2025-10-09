#include <stdio.h>
#include <stdlib.h>

#define MAXLINELEN 1000
#define TABSTOPSIZE 6

int get_line(char buffer[], int maxlen) {
    int len = 0;
    int c;
    while ((c = getchar()) != EOF && c != '\n' && len < (maxlen - 1)) buffer[len++] = c;
    if (c == '\n') buffer[len++] = c;
    buffer[len] = '\0';
    return len;
}

int detab(char buffer[], int maxlen) {
    char aux[MAXLINELEN];
    int i = 0, j = 0;
    while (buffer[i] != '\0' && j < (maxlen - 1)) {
        if (buffer[i] != '\t') {
            aux[j] = buffer[i];
            ++i;
            ++j;
        }
        else {
            int next_tabstop = ((j / TABSTOPSIZE) + 1) * TABSTOPSIZE;
            for (; j < next_tabstop; ++j)
                aux[j] = ' ';
            ++i;
        }
    }
    if (buffer[i] != '\0') return 0;
    aux[j] = '\0';
    j = 0;
    while ((buffer[j] = aux[j]) != '\0') ++j;
    return j;
}

void print_tabstop(int size) {
    for (int i = 0; i < size; ++i) {
        if (((i + 1) % TABSTOPSIZE) == 0) printf("|");
        else printf("-");
    }
    printf("\n");
}

int main() {
    char line[MAXLINELEN];
    print_tabstop(100);
    get_line(line, MAXLINELEN);
    detab(line, MAXLINELEN);
    printf("%s", line);

    return EXIT_SUCCESS;
}
