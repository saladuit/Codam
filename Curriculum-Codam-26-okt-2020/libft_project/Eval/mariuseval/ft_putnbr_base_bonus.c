/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_base_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 12:09:02 by mvan-wij      #+#    #+#                 */
/*   Updated: 2020/11/01 12:37:51 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbr_base(long long nbr, char *basechars)
{
	int			base;
	long long	pow;
	int			len;
	int			is_neg;

	base = ft_strlen(basechars);
	if (base < 2)
		return (-1);
	pow = 1;
	len = 1;
	while (nbr / base / pow != 0)
	{
		pow *= base;
		len++;
	}
	is_neg = (nbr < 0);
	if (is_neg)
		ft_putchar_fd('-', 0);
	while (pow != 0)
	{
		ft_putchar_fd(basechars[(is_neg ? -1 : 1) * (nbr / pow % base)], 0);
		pow /= base;
	}
	return (len + is_neg);
}
