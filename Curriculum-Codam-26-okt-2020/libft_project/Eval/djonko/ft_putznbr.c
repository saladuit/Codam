/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putznbr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 04:22:10 by djonker       #+#    #+#                 */
/*   Updated: 2021/02/13 22:48:54 by djonker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putznbr(int n, int e)
{
	int	s;

	s = ft_intlen(n) - e;
	while (s != 0)
	{
		ft_putchar('0');
		s++;
	}
	ft_putnbr(n);
}
