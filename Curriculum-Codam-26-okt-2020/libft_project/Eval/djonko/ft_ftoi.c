/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ftoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 21:30:30 by djonker       #+#    #+#                 */
/*   Updated: 2021/02/13 22:38:03 by djonker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ftoi(double n)
{
	int		r;
	int		l;
	double	f;

	if (ft_isneg(n))
		n = n * -1;
	l = ft_declen(n);
	r = n;
	f = n - r;
	while (l > 0)
	{
		f = f * 10;
		l--;
	}
	r = f;
	return (r);
}
