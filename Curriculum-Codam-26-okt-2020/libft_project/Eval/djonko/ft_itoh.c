/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoh.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/31 03:00:29 by djonker       #+#    #+#                 */
/*   Updated: 2021/04/01 04:05:28 by djonker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoh(double n)
{
	char	r[8];
	int		c;
	double	tf;
	int		ti;
	char	*s;

	c = 0;
	while (n != 0)
	{
		if (n < 16)
			r[c] = ft_htod(n);
		else if (n > 15)
		{
			tf = n / 16;
			ti = n / 16;
			tf = (tf - ti) * 16;
			r[c] = ft_htod(tf);
		}
		ti = n / 16;
		n = ti;
		c++;
	}
	r[c] = '\0';
	s = ft_strupp(ft_revstr(r));
	return (s);
}
