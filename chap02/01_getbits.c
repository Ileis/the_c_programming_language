#include <stdio.h>
#include <stdlib.h>
#define BYTE_SIZE 8


void print_bits(int n, const char *end) {
    char s[sizeof(int) * BYTE_SIZE + 1];
    for (int i = 0; i < sizeof(int) * BYTE_SIZE; ++i) {
        s[sizeof(int) * BYTE_SIZE - 1 - i] = (n % 2 == 0) ? '0' : '1';
        n >>= 1;
    }
    s[sizeof(int) * BYTE_SIZE] = '\0';
    printf("%s%s", s, end);
}

unsigned getbits(unsigned x, int p, int n) {
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

int main() {
    print_bits(1, "\n");
    return EXIT_SUCCESS;
}
