/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putflo.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 21:45:39 by djonker       #+#    #+#                 */
/*   Updated: 2021/02/02 21:49:06 by djonker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putflo(double n)
{
	int		i;
	int		f;

	i = n;
	f = ft_ftoi(n);
	ft_putnbr(i);
	ft_putchar('.');
	ft_putnbr(f);
}
