/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_wrdlens.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/22 12:00:13 by djonker       #+#    #+#                 */
/*   Updated: 2021/02/13 23:12:42 by djonker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wrdlens(char *s, char *c, int i)
{
	int	r;
	int	w;
	int	is;

	r = 0;
	w = 0;
	is = 0;
	while (s[is] != '\0')
	{
		while (ft_chrstr(s[is], c))
			is++;
		if (!(ft_chrstr(s[is], c)) && s[is] != '\0')
		{
			r = 0;
			while (!(ft_chrstr(s[is], c)) && s[is] != '\0')
			{
				is++;
				r++;
			}
			if (w == i)
				return (r);
			w++;
		}
	}
	return (0);
}