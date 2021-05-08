/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 08:38:54 by djonker       #+#    #+#                 */
/*   Updated: 2020/11/24 18:07:36 by djonker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			*d;
	unsigned const char		*s;
	unsigned char			u;

	d = dst;
	s = src;
	u = c;
	while (n != 0)
	{
		*d = *s;
		if (*d == u)
			return (d + 1);
		n--;
		d++;
		s++;
	}
	return (NULL);
}
