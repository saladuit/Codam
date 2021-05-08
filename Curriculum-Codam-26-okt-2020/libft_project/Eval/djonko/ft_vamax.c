/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vamax.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 04:26:11 by djonker       #+#    #+#                 */
/*   Updated: 2021/02/13 23:13:19 by djonker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_vamax(int n, ...)
{
	va_list	va;
	int		i;
	int		t;
	int		r;

	i = 0;
	va_start(va, n);
	r = -2147483648;
	while (n > i)
	{
		t = va_arg(va, int);
		if (t > r)
			r = t;
		i++;
	}
	va_end(va);
	return (r);
}
