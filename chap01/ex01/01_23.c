#include <stdio.h>
#include <stdlib.h>

#define MAXSTRLEN 1000

#define FALSE 0
#define TRUE 1

int get_file(char str[], int maxstrlen) {
    int len = 0;
    int c;
    while ((c = getchar()) != EOF && len < (maxstrlen - 1)) str[len++] = c;
    str[len] = '\0';
    return len;
}

void remove_comments(char str[]) {
    char aux[MAXSTRLEN];
    int i = 0, j = 0;
    int in_comment = FALSE;
    int in_string_or_char = FALSE;

    while (str[i] != '\0') {
        if ((i == 0 && str[i] == '\"') ||
            (str[i] == '\"' && i > 0 && str[i - 1] != '\\') ||
            (i == 0 && str[i] == '\'') ||
            (str[i] == '\'' && i > 0 && str[i - 1] != '\\')) {
            in_string_or_char = !in_string_or_char;
        }
        if (!in_string_or_char && str[i] == '/' && str[i + 1] == '*') in_comment = TRUE;
        if (!in_comment) {
            aux[j] = str[i];
            ++j;
        }
        if (!in_string_or_char && i > 0 && str[i - 1] == '*' && str[i] == '/') in_comment = FALSE;
        ++i;
    }
    aux[j] = '\0';
    j = 0;
    while((str[j] = aux[j]) != '\0') ++j;
}

int main() {
    char str[MAXSTRLEN];
    get_file(str, MAXSTRLEN);
    printf("-----------------------------------------------------------------\n");
    remove_comments(str);
    printf("%s\n", str);


    return EXIT_SUCCESS;
}
