#include <stdio.h>

int main() {
    long bc = 0;
    int c;
    while ((c = getchar()) != EOF)
        if (c == ' ' || c == '\t' || c == '\n') ++bc;
    printf("%ld\n", bc);
}
