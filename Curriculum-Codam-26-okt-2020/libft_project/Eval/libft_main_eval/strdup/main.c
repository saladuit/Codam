#include <stdio.h>
#include<string.h>
#include "../libft.h"


char	*ft_strdup(const char *s)
{
    char *p;

    p = (char*)malloc(strlen(s));
    if (!p)
        return (NULL);
    memcpy(p, s, strlen(s));
    return (p);
}

int main() {
   char *str = "Helloworld";
   char *result;
   result = ft_strdup(str);
   printf("The string : %s\n", result);
   printf("%i", str == result);
   return 0;
}