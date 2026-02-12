#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 1000

int get_line(char s[], int max) {
    int index = 0;
    int c;
    while(index < max - 1 && (c = getchar()) != EOF && c != '\n') 
        s[index++] = c;
    if (c == '\n') s[index++] = c;
    s[index] = '\0';
    return index;
}

int escape(char s[], const char t[]) {
    int index_s = 0;
    int index_t = 0;
    while (t[index_t] != '\0') {
        switch (t[index_t]) {
            case '\t':
                s[index_s++] = '\\';
                s[index_s++] = 't';
                break;
            case '\n':
                s[index_s++] = '\\';
                s[index_s++] = 'n';
                break;
            default:
                s[index_s++] = t[index_t];
                break;
        }
        index_t++;
    }
    return index_s;
}

int main() {
    char string1[MAX_LEN];
    char string2[MAX_LEN];
    get_line(string1, MAX_LEN);
    printf("%s", string1);
    escape(string2, string1);
    printf("%s", string2);
    return EXIT_SUCCESS;
}
