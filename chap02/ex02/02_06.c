#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void print_bits(int value) {
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
    printf("\n");
}

int setbits(unsigned x, int pos, int n, unsigned y) {
    int mask1 = ~(((1 << ((sizeof(int) * 8) - pos)) - 1) & ~((1 << ((sizeof(int) * 8) - pos - n)) - 1));
    int mask2 = (1 << n) - 1;

    return (x & mask1) | ((y & mask2) << (sizeof(int) * 8 - pos - n));
}

int main() {
    print_bits(setbits(0x22222222, 4, 8, 0x11111111));

    return EXIT_SUCCESS;
}
