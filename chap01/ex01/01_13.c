#include <stdio.h>

#define OUT 0
#define IN  1
#define TABLE_LEN 20

int main() {
    int histogram[TABLE_LEN];
    int state = OUT;
    int word_len = 0;
    int c;

    for (int i = 0; i < TABLE_LEN; ++i)
        histogram[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (word_len > 0)
                ++histogram[word_len - 1];
            word_len = 0;
            state = OUT;
        } else {
            ++word_len;
            state = IN;
        }
    }

    for (int i = 0; i < TABLE_LEN; ++i) {
        printf("%2d |", i + 1);
        for (int j = 0; j < histogram[i]; ++j) {
            printf("-");
        }
        printf("\n");
    }

}
