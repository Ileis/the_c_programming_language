#include <stdio.h>
#include <stdlib.h>

void squeeze(char s1[], char s2[]) {
    int k = 0;
    int c_s1_in_s2;
    for (int i = 0; s1[i] != '\0'; ++i) {
        for (int j = 0; s2[j] != '\0'; ++j) {
            c_s1_in_s2 = 0;
            if (s1[i] == s2[j]) {
                c_s1_in_s2 = 1;
                break;
            }
        }
        if (!c_s1_in_s2) s1[k++] = s1[i];
    }
    s1[k] = '\0';
}

int main() {
    char s1[] = "gabriel";
    char s2[] = "aeiou";

    squeeze(s1, s2);

    printf("%s\n", s1);

    return EXIT_SUCCESS;
}
