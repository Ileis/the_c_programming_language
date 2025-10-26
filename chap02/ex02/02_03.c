#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int ishexd(int c) {
    c = tolower(c);
    if (isdigit(c)) return c - '0';
    switch (c) {
        case 'a':
            return 10;
            break;
        case 'b':
            return 11;
            break;
        case 'c':
            return 12;
            break;
        case 'd':
            return 13;
            break;
        case 'e':
            return 14;
            break;
        case 'f':
            return 15;
            break;
    }
    return -1;
}

int htoi(char s[]) {
    int i = 0;
    int number = 0;
    int digit;
    if (s[0] == '0' && tolower(s[1]) == 'x') i = 2;
    while ((digit = ishexd(s[i++])) >= 0)
        number = (number * 16) + digit;
    return number;
}

int main() {
    char str[] = "0x10";
    printf("%d\n", htoi(str));

    return EXIT_SUCCESS;
}
