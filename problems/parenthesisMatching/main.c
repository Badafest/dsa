#include <stdio.h>
#include <stdlib.h>
// Check if a given expression has matching parenthesis or not

int isValid(char *expression);

int main()
{
    printf("Test Case: (1+3*5+(8-4)-((2-5))) [expected valid] => %d\n", isValid("(1+3*5+(8-4)-((2-5)))"));
    printf("Test Case: 1-((3-5)+4*6) [expected valid] => %d\n", isValid("1-((3-5)+4*6)"));
    printf("Test Case: (2-4)+(4-(4*6-7) [expected invalid] => %d\n", isValid("(2-4)+(4-(4*6-7)"));
}

int isValid(char *expression)
{
    int parentheses = 0;
    int returnValue = 1;
    int i = 0;
    while (expression[i] != '\0')
    {
        char c = expression[i];
        if (c == '(')
        {
            parentheses++;
        }
        else if (c == ')')
        {
            parentheses--;
        }
        i++;
    }
    return parentheses == 0 ? 1 : 0;
}