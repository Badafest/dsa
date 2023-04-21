#include <stdio.h>

void prints(char *s);

int main(void)
{
    char *s = "hello";
    prints(s);
    return 0;
}

void prints(char *s)
{
    int i = 0;
    while (s[i])
    {
        printf("%c", s[i]);
        i++;
    }
}