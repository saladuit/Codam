/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putzflo.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 21:45:39 by djonker       #+#    #+#                 */
/*   Updated: 2021/02/02 21:57:06 by djonker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putzflo(double n, int e)
{
	int		i;
	int		f;
	int		l;

	i = n;
	f = ft_ftoi(n);
	l = ft_intlen(f) - e;
	ft_putnbr(i);
	ft_putchar('.');
	ft_putnbr(f);
	while (l != 0)
	{
		ft_putchar('0');
		l++;
	}
}
