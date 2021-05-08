#include "../libft.h"
#include "/usr/include/bsd/string.h"
#include <stdio.h>
#include <ctype.h>
#include <stddef.h>

char odd_toupper(unsigned int i, char c)
{
    if (i % 2 == 0)
        return (tolower(c));
    return (toupper(c));
}

int main()
{
    char *pt;
    char str[25] = "Hallo maarten de grote";

    pt = ft_strmapi(str, &odd_toupper);
    puts(pt);
}