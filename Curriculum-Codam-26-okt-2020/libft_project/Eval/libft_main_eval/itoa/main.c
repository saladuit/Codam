#include<stdio.h>
#include "../libft.h"

// char* ft_itoa(int number) {
//    char str[20]; //create an empty string to store number
//    sprintf(str, "%d", number); //make the number into string using sprintf function
//    return str;
// }
int main() {
   int number;
   printf("Enter a number: ");
   scanf("%d", &number);
   printf("You have entered: %s", ft_itoa(number));
}