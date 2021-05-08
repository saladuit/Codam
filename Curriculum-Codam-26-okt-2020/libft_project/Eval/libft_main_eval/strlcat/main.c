#include "../libft.h"
#include "/usr/include/bsd/string.h"
#include <stdio.h>
#include <string.h>

int main()
{
    char dest1[50] = {"appelflap"};
    char dest2[50] = {"appelflap"};
    char dest3[50] = {"appelflap"};
    char dest4[50] = {"appelflap"};
    char dest5[50] = {"appelflap"};
    char dest6[50] = {"appelflap"};
    char dest7[50] = {"appelflap"};
    char dest8[50] = {"appelflap"};
    char src[20] = {"hallo maarten"};

    ft_strlcat(dest1, src, -1);
    puts(dest1);
    ft_strlcat(dest2, src, 0);
    puts(dest2);
    ft_strlcat(dest3, src, 1);
    puts(dest3);
    ft_strlcat(dest4, src, 20);
    puts(dest4);
    strlcat(dest5, src, -1);
    puts(dest5);
    strlcat(dest6, src, 0);
    puts(dest6);
    strlcat(dest7, src, 1);
    puts(dest7);
    strlcat(dest8, src, 20);
    puts(dest8);
}
