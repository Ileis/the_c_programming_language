#include <stdio.h>
#include <stdlib.h>

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

int invert(unsigned x, int p, int n) {
    unsigned mask1 = (1 << (sizeof(int) * 8 - p)) - 1;
    unsigned mask2 = (1 << (sizeof(int) * 8 - p - n)) - 1;
    print_bits(mask1 & ~mask2, "\n");
    return x ^ (mask1 & ~mask2);
}

int main() {
    unsigned value = 0x11111111;
    print_bits(value, "\n");
    print_bits(invert(value, 7, 4), "\n");
    return EXIT_SUCCESS;
}
