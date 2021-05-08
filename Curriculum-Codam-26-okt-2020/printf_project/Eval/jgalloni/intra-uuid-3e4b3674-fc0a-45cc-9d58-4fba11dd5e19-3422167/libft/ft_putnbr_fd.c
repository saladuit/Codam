/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jgalloni <jgalloni@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 15:44:35 by jgalloni      #+#    #+#                 */
/*   Updated: 2021/02/14 12:58:01 by jgalloni      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

void	ft_putnbr_fd(int n, int fd)
{
	char	str[12];
	int		i;

	i = 0;
	while (i < 12)
	{
		str[i] = '\0';
		i++;
	}
	ft_putnbr(str, n);
	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}
