/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 16:13:52 by djonker       #+#    #+#                 */
/*   Updated: 2020/12/11 22:45:00 by djonker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char				*d;
	const char			*s;
	long unsigned int	i;

	i = 0;
	d = dst;
	s = src;
	if (dst != NULL || src != NULL)
	{
		while (n > i)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}
