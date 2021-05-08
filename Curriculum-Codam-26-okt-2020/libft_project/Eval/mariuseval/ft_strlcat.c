/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 18:24:08 by mvan-wij      #+#    #+#                 */
/*   Updated: 2020/10/31 14:21:35 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int init_dstsize;
	unsigned int srcsize;
	unsigned int i;

	srcsize = ft_strlen(src);
	init_dstsize = ft_strlen(dst);
	if (init_dstsize > dstsize)
		return (dstsize + srcsize);
	i = 0;
	while (i < srcsize && i + init_dstsize < dstsize - 1)
	{
		dst[init_dstsize + i] = src[i];
		i++;
	}
	dst[init_dstsize + i] = '\0';
	return (init_dstsize + srcsize);
}
