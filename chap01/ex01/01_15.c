#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP  20

float fahr_to_cel(int fahr) {
    return (5.0 / 9.0) * (fahr - 32.0);
}

void fahr_to_cel_table(int lower, int upper, int step) {
    for (int fahr = lower; fahr <= upper; fahr += step) {
        printf("%3d %6.1f\n", fahr, fahr_to_cel(fahr));
    }
}

int main() {
    fahr_to_cel_table(LOWER, UPPER, STEP);
}
