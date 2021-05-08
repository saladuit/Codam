/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoo.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/01 01:30:17 by djonker       #+#    #+#                 */
/*   Updated: 2021/02/13 22:42:39 by djonker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_itoo(double n)
{
	char	r[20];
	int		c;
	double	tf;
	int		ti;

	c = 0;
	while (n != 0)
	{
		if (n < 8)
			r[c] = n + '0';
		else if (n > 7)
		{
			tf = n / 8;
			ti = n / 8;
			tf = (tf - ti) * 8;
			r[c] = tf + '0';
		}
		ti = n / 8;
		n = ti;
		c++;
	}
	r[c] = '\0';
	c = ft_atoi(ft_revstr(r));
	return (c);
}
