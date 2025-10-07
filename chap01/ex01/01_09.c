#include <stdio.h>

int main() {
    int c;
    int line_space;
    while ((c = getchar()) != EOF) {
        if (c == ' ') ++line_space;
        else line_space = 0;
        if (line_space < 2) putchar(c); 
    }
}
