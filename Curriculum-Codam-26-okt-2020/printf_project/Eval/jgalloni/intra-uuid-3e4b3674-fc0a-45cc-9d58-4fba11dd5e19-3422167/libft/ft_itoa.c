/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jgalloni <jgalloni@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 15:38:06 by jgalloni      #+#    #+#                 */
/*   Updated: 2021/02/14 12:56:55 by jgalloni      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(int n)
{
	int	count;

	if (n >= 0)
		count = 1;
	else
	{
		count = 2;
		if (n == -2147483648)
			n++;
		n *= -1;
	}
	while (n / 10 > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	ft_addchar(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	str[i] = c;
}

static void	ft_putnbr(char *str, int nb)
{
	if (nb == -2147483648)
	{
		ft_addchar(str, '-');
		ft_addchar(str, '2');
		ft_putnbr(str, 147483648);
	}
	else if (nb < 0)
	{
		ft_addchar(str, '-');
		ft_putnbr(str, nb * -1);
	}
	else if (nb >= 10)
	{
		ft_putnbr(str, nb / 10);
		ft_putnbr(str, nb % 10);
	}
	else
		ft_addchar(str, nb + 48);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = int_len(n);
	str = (char *)ft_calloc(len + 1, 1);
	if (!str)
		return (0);
	ft_putnbr(str, n);
	str[len] = 0;
	return (str);
}
