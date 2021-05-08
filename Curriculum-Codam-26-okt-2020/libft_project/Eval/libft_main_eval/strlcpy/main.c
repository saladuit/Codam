#include "../libft.h"
#include "/usr/include/bsd/string.h"
#include <stdio.h>

int main()
{
    char dest1[50] = {0};
    char dest2[50] = {0};
    char dest3[50] = {0};
    char dest4[50] = {0};
    char dest5[50] = {0};
    char dest6[50] = {0};
    char dest7[50] = {0};
    char dest8[50] = {0};
    char src[20] = {"hallo maarten"};

    ft_strlcpy(dest1, src, 2);
    puts(dest1);
    ft_strlcpy(dest2, src, 0);
    puts(dest2);
    ft_strlcpy(dest3, src, -1);
    puts(dest3);
    ft_strlcpy(dest4, src, 4);
    puts(dest4);
    strlcpy(dest5, src, 2);
    puts(dest5);
    strlcpy(dest6, src, 0);
    puts(dest6);
    strlcpy(dest7, src, -1);
    puts(dest7);
    strlcpy(dest8, src, 4);
    puts(dest8);
}
