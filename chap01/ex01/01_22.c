#include <stdio.h>
#include <stdlib.h>

#define MAXLINELEN 1000
#define FOLDSIZE 30
#define TRUE  1
#define FALSE 0

int get_line(char str[], int maxlen) {
    int len = 0;
    int c;
    while ((c = getchar()) != EOF && c != '\n' && len < (maxlen - 1)) str[len++] = c;
    if (c == '\n') str[len++] = c;
    str[len] = '\0';
    return len;
}

int str_len(char str[]) {
    int len = 0;
    while(str[len++] != '\0');
    return len - 1;
}

int fold(char str[], int fold_size) {
    char fold_str[MAXLINELEN];
    int fold_n = str_len(str) / fold_size;
    int i = 0, j = 0;
    int nc = 0;
    while (nc < fold_n) {
        if ((i + 1) % fold_size == 0) {
            fold_str[j++] = '\n';
            ++nc;
        }
        fold_str[j] = str[i];
        ++j;
        ++i;
    }
    int blank_line = TRUE;
    int k = i;
    while (str[k] != '\0') {
        if (str[k] != ' ' || str[k] != '\t' || str[k] != '\n') {
            blank_line = FALSE;
            break;
        }
    }
    if (blank_line == FALSE) {
        while ((fold_str[j] = str[i]) != '\0') {
            ++j;
            ++i;
        }
    }
    fold_str[j] = '\0';
    j = 0;
    while ((str[j] = fold_str[j]) != '\0') ++j;
    return j;
}

void print_fold_line(int fold_size) {
    for (int i = 0; i < fold_size - 1; ++i) putchar('-');
    printf("|\n");
}

int main() {
    char str[MAXLINELEN];
    print_fold_line(FOLDSIZE);
    get_line(str, MAXLINELEN);
    fold(str, FOLDSIZE);
    printf("%s", str);

    return EXIT_SUCCESS;
}
