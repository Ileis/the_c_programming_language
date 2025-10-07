#include <stdio.h>

#define OUT 0
#define IN  1

int main() {
    int state = OUT;
    int c;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state == IN) putchar('\n');
            state = OUT;
        } else {
            state = IN;
        }
        if (state == IN) putchar(c);
    }
}
