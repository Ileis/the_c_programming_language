#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

int main()
{
    int type;
    double op2;
    char string[MAXOP];

    while ((type = getop(string)) != EOF) {
        switch (type) {
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
