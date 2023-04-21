#include <stdio.h>
#include <stdlib.h>
// Check if a given expression has matching brackets or not

int isValid(char *expression);

typedef struct test
{
    char *expression;
    int validity;
} test;

int main()
{
    test testcases[] = {
        (test){.expression = "1+3*5+[8-4]-({2-5})", .validity = 1},
        (test){.expression = "]1-{(3-5+4*6)}", .validity = 0},
        (test){.expression = "[2-4]+[4-{4*6}-7]", .validity = 1},
    };

    for (int i = 0; i < 3; i++)
    {
        printf("TEST CASE %s [expected %d] => %d\n", testcases[i].expression, testcases[i].validity, isValid(testcases[i].expression));
    }
}

int isValid(char *expression)
{
    char *brackets = malloc(sizeof(char));
    brackets[0] = '\0';
    int returnValue = 1;
    int i = 0;
    int len = 0;
    while (expression[i] != '\0')
    {
        char c = expression[i];
        if (c == '(' || c == '{' || c == '[')
        {
            brackets[len] = c;
            len++;
            brackets = realloc(brackets, len * sizeof(char));
            brackets[len] = '\0';
        }
        else if (c == ')')
        {
            if (brackets[len - 1] != '(')
            {
                return 0;
            }
            len--;
        }
        else if (c == '}')
        {
            if (brackets[len - 1] != '{')
            {
                return 0;
            }
            len--;
        }
        else if (c == ']')
        {
            if (brackets[len - 1] != '[')
            {
                return 0;
            }
            len--;
        }
        i++;
    }
    free(brackets);
    return len == 0 ? 1 : 0;
}