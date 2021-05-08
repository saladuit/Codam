#include <stdio.h>
#include <string.h>
#include "../libft.h"

int main ()
{
const char str[] = "http://www.tutorialspoint.com";
const char ch = '.';
char *ret;
ret = ft_memchr(str, ch, strlen(str));
printf("String after |%c| is - |%s|\n", ch, ret);
return(0);
}