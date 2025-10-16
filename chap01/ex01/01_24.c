#include <stdio.h>
#include <stdlib.h>

#define MAXSTRLEN 1000
#define FALSE 0
#define TRUE 1

#define ERROR_UNMATCHED_PARENTHESES -1
#define ERROR_UNMATCHED_BRACKETS -2
#define ERROR_UNMATCHED_BRACES -3
#define ERROR_UNMATCHED_DOUBLE_QUOTES -4
#define ERROR_UNMATCHED_SINGLE_QUOTES -5

int get_str(char str[], int maxstrlen) {
    int c, len = 0;
    while ((c = getchar()) != EOF && len < (maxstrlen - 1)) str[len++] = c;
    str[len] = '\0';
    return len;
}

int check_syntax_errors(char str[], int maxstrlen) {
    int paired_parentheses = 0;
    int paired_brackets = 0;
    int paired_braces = 0;
    int in_comments = FALSE;
    int in_string = FALSE;
    int in_constchar = FALSE;
    int i = 0;
    while (str[i] != '\0') {
        if (paired_parentheses < 0) return ERROR_UNMATCHED_PARENTHESES;
        if (paired_brackets < 0) return ERROR_UNMATCHED_BRACKETS;
        if (paired_braces < 0) return ERROR_UNMATCHED_BRACES;

        if (str[i] == '/' && str[i + 1] == '*') in_comments = TRUE;
        else if (str[i] == '*' && str[i + 1] == '/') in_comments = FALSE;

        if ((i == 0 && str[i] == '\"') || (str[i] == '\"' && str[i - 1] != '\\')) in_string = !in_string;
        else if ((i == 0 && str[i] == '\'') || (str[i] == '\'' && str[i - 1] != '\\')) in_constchar = !in_constchar;

        if (!in_comments && !in_string && !in_constchar) {
            if (str[i] == '(') ++paired_parentheses;
            else if (str[i] == ')') --paired_parentheses;
            else if (str[i] == '[') ++paired_braces;
            else if (str[i] == ']') --paired_braces;
            else if (str[i] == '{') ++paired_brackets;
            else if (str[i] == '}') --paired_brackets;
        }
        ++i;
    }
    if (paired_parentheses > 0) return ERROR_UNMATCHED_PARENTHESES;
    if (paired_brackets > 0) return ERROR_UNMATCHED_BRACKETS;
    if (paired_braces > 0) return ERROR_UNMATCHED_BRACES;
    if (in_string) return ERROR_UNMATCHED_DOUBLE_QUOTES;
    if (in_constchar) return ERROR_UNMATCHED_SINGLE_QUOTES;
    return i;
}

int main() {
    char str[MAXSTRLEN];
    get_str(str, MAXSTRLEN);
    int status = check_syntax_errors(str, MAXSTRLEN);

    if (status == ERROR_UNMATCHED_PARENTHESES) printf("error: unmatched parentheses.\n");
    if (status == ERROR_UNMATCHED_BRACKETS) printf("error: unmatched brackets.\n");
    if (status == ERROR_UNMATCHED_BRACES) printf("error: unmatched braces.\n");
    if (status == ERROR_UNMATCHED_DOUBLE_QUOTES) printf("error: unmatched double quotes.\n");
    if (status == ERROR_UNMATCHED_SINGLE_QUOTES) printf("error: unmatched single quotes.\n");
    else printf("success: no rudimentary syntax errors.\n");


    return EXIT_SUCCESS;
}
