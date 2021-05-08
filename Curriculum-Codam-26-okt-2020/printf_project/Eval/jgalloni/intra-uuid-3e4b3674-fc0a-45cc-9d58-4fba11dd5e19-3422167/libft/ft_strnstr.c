/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jgalloni <jgalloni@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 21:15:20 by jgalloni      #+#    #+#                 */
/*   Updated: 2020/11/11 21:07:57 by jgalloni      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		k;

	i = 0;
	if (needle[0] == 0)
		return ((char*)haystack);
	while (i < (int)len && haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			k = 0;
			while (haystack[i + k] == needle[k] && i + k < (int)len)
			{
				if (!needle[k + 1])
					return ((char *)haystack + i);
				k++;
			}
		}
		if (!haystack[i])
			return (0);
		i++;
	}
	return (0);
}
