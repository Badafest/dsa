#include <stdio.h>
#include <stdlib.h>

void assignOperators(int j, int *pl, char *postfix, char *operators)
{
    while (operators[j] != '.')
    {
        postfix[*pl] = operators[j];
        *pl = *pl + 1;
        j--;
    }
}
// convert infix to postfix
int main(int argc, char *argv[])
{
    char *expression = argv[1];

    char *postfix = "";
    int pl = 0;
    int i = 0;

    // operator stack
    char *operators = ".";
    int len = 0;

    while (expression[i] != '\0')
    {
        char c = expression[i];
        if (c == '+' || c == '-')
        {
            assignOperators(len, &pl, postfix, operators);
            operators[1] = c;
            operators[2] = '\0';
            len = 1;
        }
        else if (c == '*' || c == '/')
        {
            len = len + 1;
            if (expression[len - 1] == '*' || expression[len - 1] == '/')
            {
                assignOperators(len - 1, &pl, postfix, operators);
                len = 1;
            }
            operators[len] = c;
            operators[len + 1] = '\0';
        }
        else
        {
            postfix[pl] = c;
            pl++;
        }
        i++;
    }
    assignOperators(len, &pl, postfix, operators);
    printf("%s => %s\n", expression, postfix);
    free(operators);
}