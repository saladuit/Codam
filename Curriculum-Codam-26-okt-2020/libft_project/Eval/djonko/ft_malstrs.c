/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_malstrs.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 15:21:11 by djonker       #+#    #+#                 */
/*   Updated: 2021/03/02 11:45:04 by djonker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_malstrs(char *s, char *c)
{
	char	*r;
	int		l;

	r = ft_calloc(ft_wrdlens((char *)s, c, 0) + 1, 1);
	if (!r)
		return (NULL);
	l = 0;
	while (*s != '\0' && !(ft_chrstr(*s, c)))
	{
		r[l] = *s;
		l++;
		s++;
	}
	return (r);
}
