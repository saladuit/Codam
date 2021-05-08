/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jgalloni <jgalloni@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 13:13:42 by jgalloni      #+#    #+#                 */
/*   Updated: 2021/02/14 14:24:22 by jgalloni      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	ch;
	int				i;
	int				len;

	len = (int)n;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	ch = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		d[i] = s[i];
		if (s[i] == ch)
			return (d + i + 1);
		i++;
	}
	return (NULL);
}
