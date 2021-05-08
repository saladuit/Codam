/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_revstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/18 11:54:50 by djonker       #+#    #+#                 */
/*   Updated: 2021/02/13 23:42:13 by djonker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_revstr(char *s)
{
	char	r[1000];
	int		is;
	int		ir;

	is = ft_strlen(s) - 1;
	ir = 0;
	while (is >= 0)
	{
		r[ir] = s[is];
		ir++;
		is--;
	}
	r[ir] = '\0';
	s = r;
	return (s);
}
