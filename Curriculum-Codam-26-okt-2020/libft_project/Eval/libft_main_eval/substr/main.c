#include "../libft.h"
#include <stdio.h>
#include<string.h>

int main()
{
    char *pt;
    char *src = "Wat ik wil";

    pt = ft_substr(src, 2, 10);
    puts(pt);
}