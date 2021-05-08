#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "../libft.h"

int main ()
{
char str1[15];
char str2[15];
int ret;
memcpy(str2, "abcdef", 6);
memcpy(str1, "ABCDEF", 6);
ret = ft_memcmp(str2, str1, 5);
if(ret > 0)
{
printf("str2 is less than str1\n");
}
else if(ret < 0)
{
printf("str1 is less than str2\n");
}
else
{
printf("str1 is equal to str2\n");
}
return(0);
}