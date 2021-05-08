/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hexa_and_unsigned.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jgalloni <jgalloni@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/21 18:37:45 by jgalloni      #+#    #+#                 */
/*   Updated: 2021/02/21 18:37:46 by jgalloni      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	string_putchar(char c, char **str)
{
	int	i;

	i = 0;
	while (*(*str + i))
		i++;
	*(*str + i) = c;
}

char	*allocate_nbr_string(unsigned long long int n, int base_len)
{
	char	*str;
	int		len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n > 0)
	{
		n = n / base_len;
		len++;
	}
	str = ft_calloc(len + 1, 1);
	return (str);
}

void	ft_putnbr_base(unsigned long long int nbr, char **str, char *base,
int base_len)
{	
	if (nbr < 0)
		ft_putnbr_base(nbr * -1, str, base, base_len);
	else if (nbr < (unsigned long int)base_len)
		string_putchar(base[nbr], str);
	else
	{
		ft_putnbr_base(nbr / base_len, str, base, base_len);
		ft_putnbr_base(nbr % base_len, str, base, base_len);
	}
}

char	*itoa_nbr_base(unsigned long long int nbr, char *base)
{
	char	*str;
	int		base_len;

	base_len = ft_strlen(base);
	str = allocate_nbr_string(nbr, base_len);
	if (!str)
		return (str);
	ft_putnbr_base(nbr, &str, base, base_len);
	return (str);
}
