#include <stdio.h> 
#include <string.h> 
#include "../libft.h"

int main() 
{ 
    char str[] = "Geeks-for-Geeks"; 
  
    // Returns first token  
    char **token = ft_split(str, '-'); 
    
    // Keep printing tokens while one of the 
    // delimiters present in str[]. 
    while (*token != NULL) 
    { 
        printf("%s\n", *token);
        token++;
    } 
  
    return 0; 
} 