/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 08:35:56 by djonker       #+#    #+#                 */
/*   Updated: 2021/03/30 17:46:31 by djonker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*p;
	unsigned char		t;

	t = (unsigned char)c;
	p = (unsigned char *)s;
	while (n > 0)
	{
		if (t == *p)
			return ((void *)p);
		n--;
		++p;
	}
	return (NULL);
}
