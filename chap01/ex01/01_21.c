#include <stdio.h>
#include <stdlib.h>

#define MAXLINELEN 1000
#define TABSTOPSIZE 10

int get_line(char buffer[], int maxlen) {
    int len = 0;
    int c;
    while ((c = getchar()) != EOF && c != '\n' && len < (maxlen - 1)) buffer[len++] = c;
    if (c == '\n') buffer[len++] = c;
    buffer[len] = '\0';
    return len;
}

int entab(char str[]) {
    char aux[MAXLINELEN];
    int i = 0, j = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ') {
            int next_tabstop = ((i / TABSTOPSIZE) + 1) * TABSTOPSIZE;
            int k;
            for (k = 0; (k + i) < next_tabstop && str[k + i] == ' '; ++k);
            if ((i + k) == next_tabstop) {
                aux[j++] = '\t';
                i += k;
            }
            else {
                int blank_space = (i + k);
                while (i < blank_space) {
                    aux[j] = str[i];
                    ++j;
                    ++i;
                }
            }
        }
        else {
            aux[j] = str[i];
            ++j;
            ++i;
        }
    }
    aux[j] = '\0';
    j = 0;
    while ((str[j] = aux[j]) != '\0') ++j;
    return j;
}

void print_visible_tabs(char str[]) {
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '\t') printf("\\t");
        else putchar(str[i]);
    }
}

void print_tabstop(int size) {
    for (int i = 0; i < size; ++i) {
        if (((i + 1) % TABSTOPSIZE) == 0) printf("|");
        else printf("-");
    }
    printf("\n");
}

int main() {
    char str[MAXLINELEN];
    print_tabstop(100);
    get_line(str, MAXLINELEN);
    entab(str);
    print_visible_tabs(str);

    return EXIT_SUCCESS;
}
