#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
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

    return EXIT_SUCCESS;
}
