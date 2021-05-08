#include "../libft.h"
#include "/usr/include/bsd/string.h"
#include <stdio.h>

int main()
{
    ft_putnbr_fd(2147483647, 1);
    ft_putchar_fd('\n', 1);
    ft_putnbr_fd(-2147483648, 1);
    ft_putchar_fd('\n', 1);
    ft_putnbr_fd(0, 1);
    ft_putchar_fd('\n', 1);
    ft_putnbr_fd(4456, 1);
    ft_putchar_fd('\n', 1);
}