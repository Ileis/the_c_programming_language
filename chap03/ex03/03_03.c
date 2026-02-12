#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_LEN 1000

typedef enum state {
    START,
    START_HYPHEN,

    FST_NUMERAL_INTERVAL,
    HYPHEN_NUMERAL_INTERVAL,
    SCD_NUMERAL_INTERVAL,
    INVALID_NUMERAL_INTERVAL,

    FST_LETTER_INTERVAL,
    HYPHEN_LETTER_INTERVAL,
    SCD_LETTER_INTERVAL,
    INVALID_LETTER_INTERVAL
}state;

int expand(const char s1[], char s2[]) {
    int c;
    int index_s2 = 0;
    state q = START;
    int fst_term;
    int scd_term;

    for (int index_s1 = 0; index_s1 <= strlen(s1); ++index_s1) {
        if (index_s1 < strlen(s1))
            c = s1[index_s1];
        switch (q) {
            case START:
                if (isdigit(c)) {
                    q = FST_NUMERAL_INTERVAL;
                    fst_term = c;
                } else if (isalpha(c)) {
                    q = FST_LETTER_INTERVAL;
                    fst_term = c;
                } else if (c == '-') {
                    q = START_HYPHEN;
                    s2[index_s2++] = c;
                }
                break;

            case START_HYPHEN:
                if (isdigit(c)) {
                    q = FST_NUMERAL_INTERVAL;
                    fst_term = c;
                } else if (isalpha(c)) {
                    q = FST_LETTER_INTERVAL;
                    fst_term = c;
                } else if (c == '-') {
                    s2[index_s2++] = c;
                }
                break;

            case FST_NUMERAL_INTERVAL:
                if (isdigit(c)) {
                    s2[index_s2++] = fst_term;
                    fst_term = c;
                } else if (isalpha(c)) {
                    q = INVALID_NUMERAL_INTERVAL;
                } else if (c == '-') {
                    q = HYPHEN_NUMERAL_INTERVAL;
                }
                break;

            case HYPHEN_NUMERAL_INTERVAL:
                if (isdigit(c)) {
                    q = SCD_NUMERAL_INTERVAL;
                    scd_term = c;
                } else if (isalpha(c)) {
                    q = INVALID_NUMERAL_INTERVAL;
                } else if (c == '-') {
                    q = INVALID_NUMERAL_INTERVAL;
                }
                break;

            case SCD_NUMERAL_INTERVAL:
                for (int i = fst_term, inc = (fst_term - scd_term > 0) ? (-1) : (1); i != scd_term; i += inc) s2[index_s2++] = i;
                s2[index_s2++] = scd_term; 
                fst_term = scd_term;

                if (isdigit(c)) {
                    q = FST_NUMERAL_INTERVAL;
                    fst_term = c;
                } else if (isalpha(c)) {
                    q = FST_LETTER_INTERVAL;
                    fst_term = c;
                } else if (c == '-') {
                    q = HYPHEN_NUMERAL_INTERVAL;
                }
                break;

            case INVALID_NUMERAL_INTERVAL:
                return 0;
                break;

            case FST_LETTER_INTERVAL:
                if (isdigit(c)) {
                    q = INVALID_LETTER_INTERVAL;
                } else if (isalpha(c)) {
                    s2[index_s2++] = fst_term;
                    fst_term = c;
                } else if (c == '-') {
                    q = HYPHEN_LETTER_INTERVAL;
                }
                break;

            case HYPHEN_LETTER_INTERVAL:
                if (isdigit(c)) {
                    q = INVALID_LETTER_INTERVAL;
                } else if (isalpha(c)) {
                    q = SCD_LETTER_INTERVAL;
                    scd_term = c;
                } else if (c == '-') {
                    q = INVALID_LETTER_INTERVAL;
                }
                break;

            case SCD_LETTER_INTERVAL:
                for (int i = fst_term, inc = (fst_term - scd_term > 0) ? (-1) : (1); i != scd_term; i += inc) s2[index_s2++] = i;
                s2[index_s2++] = scd_term;
                fst_term = scd_term;

                if (isdigit(c)) {
                    q = FST_NUMERAL_INTERVAL;
                    fst_term = c;
                } else if (isalpha(c)) {
                    q = FST_LETTER_INTERVAL;
                    fst_term = c;
                } else if (c == '-') {
                    q = HYPHEN_LETTER_INTERVAL;
                }
                break;

            case INVALID_LETTER_INTERVAL:
                return 0;
                break;

            default:
                return 0;
                break;
        }
        printf("rodada\ts1:%c\ts2:%c\n", c, s2[index_s2 - 1]);
    }

    printf("\n");
     if (q == INVALID_NUMERAL_INTERVAL || q == INVALID_LETTER_INTERVAL || q == HYPHEN_NUMERAL_INTERVAL || q == HYPHEN_LETTER_INTERVAL)
        return 0;

    s2[index_s2] = '\0';
    return index_s2;
}

int main() {
    char s1[] = "0-9a-z";
    char s2[MAX_LEN];

    int len = expand(s1, s2);
    printf("%s\n", s1);
    printf("%s\n", s2);
    printf("len: %d\n", len);

    return EXIT_SUCCESS;
}
