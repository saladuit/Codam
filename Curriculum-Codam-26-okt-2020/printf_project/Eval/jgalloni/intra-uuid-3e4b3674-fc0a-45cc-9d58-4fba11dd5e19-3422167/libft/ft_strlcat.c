/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jgalloni <jgalloni@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 16:52:48 by jgalloni      #+#    #+#                 */
/*   Updated: 2020/11/04 17:08:08 by jgalloni      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int	i;
	int	k;
	int	dst_len;

	k = 0;
	i = 0;
	dst_len = ft_strlen(dst);
	if (dst_len >= (int)dstsize)
		return (dstsize + ft_strlen(src));
	while (dst[i] != 0)
	{
		i++;
	}
	while (k < (int)dstsize - i - 1 && src[k])
	{
		dst[k + i] = src[k];
		k++;
	}
	if (dstsize)
		dst[k + i] = 0;
	return (dst_len + ft_strlen(src));
}
