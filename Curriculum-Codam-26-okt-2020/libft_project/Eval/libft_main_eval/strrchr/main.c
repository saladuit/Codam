#include <stdio.h>
#include <string.h>
#include "../libft.h"

int main ()
{
int len;
const char str[] = "http://www.tutorialspoint.com";
const char ch = '.';
char *ret;
ret = ft_strrchr(str, ch);
printf("String after |%c| is - |%s|\n", ch, ret);
return(0);
}