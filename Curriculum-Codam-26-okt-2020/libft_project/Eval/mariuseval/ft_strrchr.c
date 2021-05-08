/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 10:58:19 by mvan-wij      #+#    #+#                 */
/*   Updated: 2020/10/31 14:22:08 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s) - 1;
	if (c == '\0')
		return ((char *)(s) + i + 1);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s) + i);
		i--;
	}
	return (NULL);
}
