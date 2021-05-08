/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jgalloni <jgalloni@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 21:07:08 by jgalloni      #+#    #+#                 */
/*   Updated: 2021/02/14 13:06:03 by jgalloni      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	int			i;

	d = dst;
	s = src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	if (d < s)
	{
		while (i < (int)n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
