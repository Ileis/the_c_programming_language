#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 1000

void reverse(char string[]) {
    int len;
    for (len = 0; string[len] != '\0'; ++len);
    for (int i = 0, j = len - 1; i < j; ++i, --j) {
        int aux;
        aux = string[i], string[i] = string[j], string[j] = aux;
    }
}

void itoa(int number, char string[], int len) {
    int index_string = 0;
    do {
        string[index_string++] = (number % 10) + '0';
    } while ((number /= 10) > 0);
    printf("%d\n", index_string);
    while (index_string < len) string[index_string++] = '0';
    string[index_string] = '\0';
    reverse(string);
}

int main() {
    char string[MAX_LEN];
    int number = 12345;
    itoa(number, string, 10);
    printf("%s\n", string);

    return EXIT_SUCCESS;
}
