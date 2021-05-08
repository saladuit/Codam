#include <stdio.h>
#include <string.h>
#include "../libft.h"

int main () {
   char src[50], dest[50];
   char *pt;

   strcpy(src,  "This is source");
   strcpy(dest, "This is destination");

   pt =ft_strjoin(dest, src);

   printf("Final destination string : |%s|", pt);
   
   return(0);
}
