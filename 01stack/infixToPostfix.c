#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

char associativity(char c) {
    if (c == '^')
        return 'R';
    return 'L'; // Default to left-associative
}

void infixToPostfix(char s[]) {
    char result[1000];
    int resultIndex = 0;
    int len = strlen(s);
    char stack[1000];
    int stackIndex = -1;

    for (int i = 0; i < len; i++) {
        char c = s[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            result[resultIndex++] = c;
        }
        else if (c == '(') {
            stack[++stackIndex] = c;
        }
        else if (c == ')') {
            while (stackIndex >= 0 && stack[stackIndex] != '(') {
                result[resultIndex++] = stack[stackIndex--];
            }
            stackIndex--; // Pop '('
        }
        else {
            while (stackIndex >= 0 && (prec(s[i]) < prec(stack[stackIndex]) ||
                                       prec(s[i]) == prec(stack[stackIndex]) &&
                                           associativity(s[i]) == 'L')) {
                result[resultIndex++] = stack[stackIndex--];
            }
            stack[++stackIndex] = c;
        }
    }

    while (stackIndex >= 0) {
        result[resultIndex++] = stack[stackIndex--];
    }

    result[resultIndex] = '\0';
    printf("%s\n", result);
}

int main() {
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";

    infixToPostfix(exp);

    return 0;
}
