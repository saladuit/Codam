#include "../libft.h"
#include "/usr/include/bsd/string.h"
#include <stdio.h>
#include <ctype.h>

int main()
{
    char *pt;
    char str[] = "        Hallo maarten de grote    ";

    pt = ft_strtrim(str, "   ");
    puts(pt);
}
