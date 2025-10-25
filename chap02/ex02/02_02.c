#include <stdio.h>

int get_line(char s[], int lim) {
    int c, i = 0;
    // for (i = 0; i < lim - 1 && (c=getchar()) != '\n' && c != EOF; ++i)
    while (i < lim - 1)
        if ((c = getchar()) != '\n') {
            if (c != EOF) s[i++] = c;
            else break;
        }
        else break;
    if (c == '\n') s[i++] = c;
    s[i] = '\0';
    return i;
}

int main() {
    int len = 10;
    char str[len];
    get_line(str, len);
    printf("%s", str);
}
