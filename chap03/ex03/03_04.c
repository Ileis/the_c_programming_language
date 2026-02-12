// INT_MIN * -1: overflow
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// range de valores para a representacao int: INT_MIN..(INT_MIN * -1) - 1=INT_MAX
int main() {
    printf("INT_MIN: %d\n", INT_MIN);
    printf("INT_MAX: %d\n", INT_MAX);
    printf("%d\n", INT_MIN * -1 - 1);
    return EXIT_SUCCESS;
}
