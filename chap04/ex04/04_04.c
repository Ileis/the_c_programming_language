#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100

typedef enum operator {
    NUMBER,
    CLEAR,
    SWAP,
    PRINT,
    DUPLICATE,
    INVALID_OP
}operator;

int getop(char[]);
void clear_stack(void);
void push(double);
double pop(void);
double top(void);
int getch(void);
void ungetch(int);

int main()
{
    int type;
    double op2;
    char string[MAXOP];

    while ((type = getop(string)) != EOF) {
        switch (type) {
            case CLEAR: {
                clear_stack();
                break;
            }
            case SWAP: {
                double op2 = pop();
                double op1 = pop();
                push(op2);
                push(op1);
                break;
            }
            case PRINT: {
                printf("print:\t%g\n", top());
                break;
            }
            case DUPLICATE: {
                push(top());
                break;
            }
            case NUMBER: {
                push(atof(string));
                break;
            }
            case '%': {
                op2 = pop();
                push(fmod(pop(), op2));
                break;
            }
            case '+': {
                push(pop() + pop());
                break;
            }
            case '*': {
                push(pop() * pop());
                break;
            }
            case '-': {
                op2 = pop();
                push(pop() - op2);
                break;
            }
            case '/': {
                op2 = pop();
                if (op2 != 0.0) push(pop() / op2);
                else printf("error: zero dividisor\n");
                break;
            }
            case '\n': {
                printf("\t%.8g\n", pop());
                break;
            }
            default: {
                printf("error: unknown command %s\n", string);
                break;
            }
        }
    }
    return EXIT_SUCCESS;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void clear_stack()
{
    sp = 0;
}

double top(void)
{
    return (sp > 0) ? val[sp-1] : 0;
}

void push(double value)
{
    if (sp < MAXVAL) val[sp++] = value;
    else 
        printf("error: stack full, can't push %g\n", value);
}

double pop(void)
{
    if (sp > 0) return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0;
    }
}

int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    i = 0;
    if (isalpha(c)) {
        while (isalpha(s[++i] = c = getch()));
        ungetch(c);
        s[i] = '\0';
        if (strcmp(s, "clear") == 0) return CLEAR;
        else if (strcmp(s, "swap") == 0) return SWAP;
        else if (strcmp(s, "print") == 0) return PRINT;
        else if (strcmp(s, "duplicate") == 0) return DUPLICATE;
        else return INVALID_OP;
    }
    if (c == '-') {
        s[++i] = c = getch();
        if (!isdigit(s[i])) {
            ungetch(s[i]);
            s[i--] = '\0';
            return s[i];
        }
    }
    if (!isdigit(c) && c != '.') return c;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()));

    if (c == '.')
        while (isdigit(s[++i] = c = getch()));

    s[i] = '\0';
    if (c != EOF) ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE) printf("ungetch: too many characters\n");
    else buf[bufp++] = c;
}
