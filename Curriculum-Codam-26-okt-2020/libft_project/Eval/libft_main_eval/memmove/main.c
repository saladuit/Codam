#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "../libft.h"

int main ()
{
const char dest[] = "oldstring";
const char src[] = "oewstring";
printf("Before memmove dest = %s, src = %s\n", dest, src);
ft_memmove(((void*)dest), src, 9);
printf("After memmove dest = %s, src = %s\n", dest, src);
return(0);
}