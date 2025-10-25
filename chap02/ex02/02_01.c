#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

long long ipow(long long base, long long exp) {
    long long result = 1;
    if (exp < 0) return 0;
    while (exp > 0) {
        if (exp % 2 == 1) result *= base;
        base *= base;
        exp /= 2;
    }
    return result;
}

void computed_limits(void) {
    // signed
    int schar_min = -1 * ipow(2, 8 * sizeof(signed char) - 1);
    int schar_max = ipow(2, 8 * sizeof(signed char) - 1) - 1;
    int shrt_min = -1 * ipow(2, 8 * sizeof(signed short) - 1);
    int shrt_max = ipow(2, 8 * sizeof(signed short) - 1) - 1;
    int int_min = -1 * ipow(2, 8 * sizeof(signed int) - 1);
    int int_max = ipow(2, 8 * sizeof(signed int) - 1) - 1;
    long long_min = -1 * ipow(2, 8 * sizeof(signed long) - 1);
    long long_max = ipow(2, 8 * sizeof(signed long) - 1) - 1;
    // unsigned
    int uchar_max = ipow(2, 8 * sizeof(unsigned char)) - 1;
    int ushrt_max = ipow(2, 8 * sizeof(unsigned short)) - 1;
    unsigned int uint_max = ipow(2, 8 * sizeof(unsigned int)) - 1;
    unsigned long ulong_max = ipow(2, 8 * sizeof(unsigned long)) - 1;


    printf("---------- C LIMITS ----------\n");
    printf("---------- SIGNED ----------\n");
    printf("char:\t%d -- %d\n", schar_min, schar_max);
    printf("short:\t%d -- %d\n", shrt_min, shrt_max);
    printf("int:\t%d -- %d\n", int_min, int_max);
    printf("long:\t%ld -- %ld\n", long_min, long_max);
    printf("---------- UNSIGNED ----------\n");
    printf("unsigned char:\t%d -- %d\n", 0, uchar_max);
    printf("unsigned short:\t%d -- %d\n", 0, ushrt_max);
    printf("unsigned int:\t%d -- %u\n", 0, uint_max);
    printf("unsigned long:\t%d -- %lu\n", 0, ulong_max);
}

void headed_limits(void) {
    printf("---------- H LIMITS ----------\n");
    printf("---------- SIGNED ----------\n");
    printf("char:\t%d -- %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("short:\t%d -- %d\n", SHRT_MIN, SHRT_MAX);
    printf("int:\t%d -- %d\n", INT_MIN, INT_MAX);
    printf("long:\t%ld -- %ld\n", LONG_MIN, LONG_MAX);
    printf("---------- UNSIGNED ----------\n");
    printf("unsigned char:\t%d -- %d\n", 0, UCHAR_MAX);
    printf("unsigned short:\t%d -- %d\n", 0, USHRT_MAX);
    printf("unsigned int:\t%d -- %u\n", 0, UINT_MAX);
    printf("unsigned long:\t%d -- %lu\n", 0, ULONG_MAX);
}

int main() {
    computed_limits();
    headed_limits();

    return EXIT_SUCCESS;
}
