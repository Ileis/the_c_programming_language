#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_LEN 1000

void reverse(char string[]) {
    int len;
    for (len = 0; string[len] != '\0'; ++len);
    for (int i = 0, j = len - 1; i < j; ++i, --j) {
        int aux;
        aux = string[i], string[i] = string[j], string[j] = aux;
    }
}

int itob(int number, char string[], int base) {
    int string_len = 0;
    if (number > 0) {
        while (number > 0) {
            int reminder = number % base;
            if (reminder < 9) string[string_len++] = reminder + '0';
            else string[string_len++] = reminder - 10 + 'a';
            number /= base;
        }
    } else {
        string[string_len++] = '0';
    }
    string[string_len] = '\0';
    reverse(string);
    return string_len;
}

int main() {
    int number = INT_MAX;
    int base = 16;
    char string[MAX_LEN];
    itob(number, string, base);
    printf("number in base 10: %d\n", number);
    printf("number in base %d: %s\n", base, string);
    return EXIT_SUCCESS;
}
