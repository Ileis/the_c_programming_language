#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void print_bits(int value, const char *end) {
    int size = (sizeof(int) * 8);
    char buff[size];
    for (int i = size - 1; i >= 0; --i) {
        buff[i] = (value % 2) ? '1' : '0';
        value /= 2;
    }
    for (int i = 0; i < size; i++) {
        if (i > 0 && i % 4 == 0) printf(" | ");
        putchar(buff[i]);
    }
    printf("%s", end);
}

int rightrot(unsigned x, int n) {
    int size = sizeof(int) * 8;
    n %= size;
    return (x >> n) | (x << (size - n));
}

int main() {
    unsigned value = 0x12345678;
    print_bits(value, "\n");
    print_bits(rightrot(value, 8 * sizeof(value) / 2), "\n");
    print_bits(rightrot(value, 1), "\n");
    return EXIT_SUCCESS;
}
