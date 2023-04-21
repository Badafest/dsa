#include <stdio.h>

char *sequal(char *s1, char *s2);

int main(void)
{
    char *string1 = "hello";
    char *string2 = "hello";
    char *string3 = "bye";
    printf("%s and %s are %s\n", string1, string2, sequal(string1, string2));
    printf("%s and %s are %s\n", string1, string3, sequal(string1, string3));
}

char *sequal(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] || s2[i])
    {
        if (s1[i] != s2[i])
        {
            return "Not Equal";
        }
        i++;
    }
    return "Equal";
}